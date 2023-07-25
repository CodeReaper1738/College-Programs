import argparse
import random
import socket

class Server:
    def __init__(self, port, logfile):
        #self.ip = "10.128.0.2"
        self.port = port
        self.logfile = logfile
        with open('quotes.txt') as f:
            self.quotes = f.readlines()

    def run(self):
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

        try:
            sock.bind(('', self.port))
        except Exception as e:
            print(f"Error binding to {self.port}: {e}")
            return

        sock.listen()
        print(f"Listening on {self.port}...")

        while True:
            try:
                conn, addr = sock.accept()
                print(f"Connection from {addr}")

                with open(self.logfile, 'a') as f:
                    f.write(f"Connection from {addr}\n")

                data = conn.recv(1024)
                if b'network' in data.lower():
                    quote = random.choice(self.quotes).encode()
                    print(quote)
                    conn.sendall(quote)
                    with open(self.logfile, 'a') as f:
                        f.write("Sent quote '{}' to {}\n".format(quote.decode(), addr))
                else:
                    conn.sendall(b"Invalid request")

                conn.close()

            except KeyboardInterrupt:
                break
            except Exception as e:
                print(f"Error handling connection: {e}")
                continue

        sock.close()


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('-p', '--port', type=int, required=True, help="Server port number")
    parser.add_argument('-l', '--logfile', type=str, required=True, help="Log file name")
    args = parser.parse_args()

    server = Server(args.port, args.logfile)
    server.run()