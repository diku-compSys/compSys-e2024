import random
import socket
import socketserver
import threading

MSG_MAX = 128
TEST_MSG = "test"
INTERNAL_MSG = "int"

class NestedServer(socketserver.ThreadingTCPServer):
    def __init__(self, ip, port, handler, nodes):
        super().__init__((ip, port), handler)
        self.nodes = nodes

class NestingHandler(socketserver.StreamRequestHandler):
    def handle(self):
        _, my_port = self.server.server_address
        random_node = self.server.nodes[random.randint(0, len(self.server.nodes)-1)]

        try:
            bytes_message = self.request.recv(MSG_MAX)
            str_message = bytes_message.decode("utf-8")
            
            if (str_message.startswith(TEST_MSG)):

                nest_request = bytearray()
                nest_request.extend(INTERNAL_MSG.encode("utf-8"))
                nest_request.extend('-'.encode())
                nest_request.extend(str(my_port).encode("utf-8"))

                with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as nest_socket:
                    nest_socket.connect(("127.0.0.1", random_node))
                    nest_socket.sendall(nest_request)

                    nest_bytes = nest_socket.recv(MSG_MAX)
                    nest_str = nest_bytes.decode("utf-8")

                    unique_nodes = set(nest_str[4:].split('-'))
                    response = f"Went via {len(unique_nodes)} unique nodes\n".encode("utf-8")

            elif (str_message.startswith(INTERNAL_MSG)):
                response = bytearray(bytes_message)
                response.extend('-'.encode("utf-8"))
                response.extend(str(my_port).encode("utf-8"))

                if len(response) < MSG_MAX-6:
                    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as nest_socket:
                        nest_socket.connect(("127.0.0.1", random_node))
                        nest_socket.sendall(response)

                        response = nest_socket.recv(MSG_MAX)

            else:         
                response = b"Invalid request\n"

            self.request.sendall(response)

        except:
            pass

def NestingThread(nodes, i, n):
    with NestedServer("127.0.0.1", nodes[i], NestingHandler, nodes) as nested_server:
        try:
            nested_server.serve_forever()
        finally:
            nested_server.server_close()

if __name__ == "__main__":
    base_port = 12345
    node_n = 20
    nodes = [i for i in range(base_port, base_port+node_n)]

    socketserver.ThreadingTCPServer.allow_reuse_address = True

    for i, node in enumerate(nodes):
        thread = threading.Thread(target=NestingThread, args=(nodes, i, node_n))
        thread.start()

