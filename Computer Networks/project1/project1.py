import argparse
import socket

class Client:
    def __init__(self, server_ip, server_port):
        self.server_ip = server_ip
        self.server_port = server_port
        self.socket = None

    def create_socket(self):
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    def connect(self):
        try:
            self.socket.connect((self.server_ip, self.server_port))
            print("Connected to server")
        except socket.error as error:
            print("Error connecting to server")
            exit(1)

    def send_message(self, message):
        try:
            self.socket.sendall(message.encode())
        except ConnectionError:
            print("Error to send message to server")
            exit(1)

    def receive_message(self):
        try: 
            message = self.socket.recv(1024).decode()
        except ConnectionError:
            print("Error to receive message from server")
            exit(1)
        return message

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("-s", "--server", required=True, help="Server IP address")
    parser.add_argument("-p", "--port", type=int, required=True, help="Server port number")
    parser.add_argument("-l", "--log", required=True, help="Log file name")
    args = parser.parse_args()

    client = Client(args.server, args.port)
    client.create_socket()
    client.connect()

    message = input("Enter message: ")
    client.send_message(message)

    if "network" in message.lower():
        print("Easter egg activated!")
        response = client.receive_message()
        print("Server response:", response)
        with open(args.log, "a") as log_file:
            log_file.write(response + "\n")

        client.socket.shutdown(socket.SHUT_RDWR)
        client.socket.close()
    else: 
        print("The word Network was not found within that sentence")

if __name__=="__main__":
    main()