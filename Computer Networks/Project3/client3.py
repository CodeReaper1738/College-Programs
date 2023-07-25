import argparse
import struct
import socket

class Client:
    def __init__(self, server, port, logfile):
        self.server = server
        self.port = port
        self.logfile = logfile

    def run(self):
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

        with open(self.logfile, 'a') as log:
            try:
                sock.connect((self.server, self.port))
            except Exception as e:
                msg = f"Error connecting to {self.host}:{self.port}: {e}"
                print(msg)
                log.write(msg + "\n")
                return
            
            msg = f"Sending Hello Packet"
            print(msg)
            log.write(msg + "\n")

            version = 17
            packet = struct.pack('!IB5s', version, 1, b"hello")
            sock.sendall(packet)

            response = sock.recv(1024)
            vm_version, packet_type, message_bytes = struct.unpack('!IB5s', response)
            message = message_bytes.decode()
            packet_size = len(message)

            msg = f"Received Data: Version: {vm_version}, Type: {packet_type}, length {packet_size} "
            print(msg)
            log.write(msg + "\n")

            if vm_version != 17:
                msg = 'Version denied'
                print(msg)
                log.write(msg + "\n")
                sock.close()
                return
            else:
                msg ='Version accepted'
                print(msg)
                log.write(msg + "\n")

                msg = f"Received Message " + message
                print(msg)
                log.write(msg + "\n")

            while True:
                message = input("Enter a message (LIGHTON, LIGHTOFF, DISCONNECT): ")
                log.write("Enter a message (LIGHTON, LIGHTOFF, DISCONNECT): " + message + "\n")

                msg = f"Sending Command"
                print(msg)
                log.write(msg + "\n")

                print(message)
                
                if message == "LIGHTON":
                    message_type = 1
                elif message == "LIGHTOFF":
                    message_type = 2
                else: 
                    message = "DISCONNECT"
                    message_type = 3
                    
                #packet = struct.pack('!IB', vm_version, message_type)
                #sock.sendall(packet)

                packet = struct.pack('>III', 17, message_type, len(message)) + message.encode()
                sock.sendall(packet)

               # response = sock.recv(1024)
                #vm_version, packet_type, message_bytes = struct.unpack('!IB8s', response)
                #recv_message = sock.recv(message_bytes)
                #message = recv_message.decode()

                #response = sock.recv(struct.calcsize('>III'))
                #vm_version, packet_type, message = struct.unpack('>III', response)
                
                
                response = sock.recv(struct.calcsize('>III'))
                vm_version, packet_type, message_bytes = struct.unpack('>III', response)
                recv_message = sock.recv(message_bytes)
                message = recv_message.decode()
                #message = message_bytes.decode()
                #packet_size = len(message)

                msg = f"Received Data: Version: {vm_version}, Type: {packet_type}, length {message_bytes} "
                print(msg)
                log.write(msg + "\n")
                
                if vm_version != 17:
                    msg = 'Version denied'
                    print(msg)
                    log.write(msg + "\n")
                    sock.close()
                    return
                else:
                    msg ='Version accepted'
                    print(msg)
                    log.write(msg + "\n")
                
                msg = f"Received Message " + message
                print(msg)
                log.write(msg + "\n")

                if packet_type == 1 or packet_type == 2:
                    msg = f"Command Successfull"
                    print(msg)
                    log.write(msg + "\n")
                else:
                    msg = f"Error Running Command"
                    print(msg)
                    log.write(msg + "\n")

                if message_type == 3:
                    msg = "Closing Socket"
                    print(msg)
                    log.write(msg + "\n")
                    sock.close()
                    break

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('-s', '--server', type=str, required=True, help="Server IP address")
    parser.add_argument('-p', '--port', type=int, required=True, help="Server port number")
    parser.add_argument("-l", "--logfile", required=True, help="Log file name")
    args = parser.parse_args()

    client = Client(args.server, args.port, args.logfile)
    client.run()