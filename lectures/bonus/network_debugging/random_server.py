import random
import socketserver

MSG_MAX = 1024

class RandomServer(socketserver.ThreadingTCPServer):
    def __init__(self, ip, port, handler):
        super().__init__((ip, port), handler)


class MysteryHandler(socketserver.StreamRequestHandler):
    def handle(self):
        try:
            bytes_message = self.request.recv(MSG_MAX)

            response = bytearray()
            response.extend(bytes_message[-2::-1])
            response.extend('\n'.encode())

            self.request.sendall(response)
        except:
            pass


if __name__ == "__main__":
    port = random.randint(1000, 65000)

    with RandomServer("127.0.0.1", port, MysteryHandler) as random_server:
        try:
            random_server.serve_forever()
        finally:
            random_server.server_close()
