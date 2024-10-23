import argparse
import random
import socketserver

MSG_MAX = 1024

class EchoHandler(socketserver.StreamRequestHandler):
    def handle(self):
        try:
            bytes_message = self.request.recv(MSG_MAX)
            self.request.sendall(bytes_message)
        except:
            pass


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("port", type=int)
    args = parser.parse_args()

    port = args.port

    socketserver.ThreadingTCPServer.allow_reuse_address = True
    with socketserver.ThreadingTCPServer(("127.0.0.1", port), EchoHandler) as random_server:
        try:
            random_server.serve_forever()
        finally:
            random_server.server_close()