import argparse
import socket

class Client:
    def __init__(self, host, port, logfile):
        self.host = host
        self.port = port
        self.logfile = logfile
    def run(self):
        while True:
            message = input("Enter a message: ")

            sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            try:
                sock.connect((self.host, self.port))
            except Exception as e:
                print(f"Error connecting to {self.host}:{self.port}: {e}")
                return

            sock.sendall(message.encode())

            
            response = sock.recv(1024)
            
            print(response.decode())
            with open(self.logfile, 'a') as f:
                f.write(response.decode("utf-8") + "\n")
            sock.close()

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('-i', '--host', type=str, required=True, help="Server IP address")
    parser.add_argument('-p', '--port', type=int, required=True, help="Server port number")
    parser.add_argument("-l", "--logfile", required=True, help="Log file name")
    args = parser.parse_args()


    client = Client(args.host, args.port, args.logfile)
    client.run()