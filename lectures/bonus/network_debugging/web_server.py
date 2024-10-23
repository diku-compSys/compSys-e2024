import http.server
import socketserver

PORT = 1234

class MyHandler(http.server.SimpleHTTPRequestHandler):
    def do_GET(self):
        self.send_response(200)
        
        self.send_header('Content-type', 'text/html')
        self.end_headers()
        
        self.wfile.write(b"<html><body><h1>Best website ever</h1></body></html>")

if __name__ == "__main__":
    socketserver.ThreadingTCPServer.allow_reuse_address = True
    with socketserver.ThreadingTCPServer(("127.0.0.1", PORT), MyHandler) as http_server:
        print(f"Serving on port {PORT}")
        try:
            http_server.serve_forever()
        finally:
            http_server.server_close()