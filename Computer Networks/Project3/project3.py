import argparse
import struct
import socket
import threading

class Server:
    def __init__(self, port, logfile):    
        self.port = port
        self.logfile = logfile


    def handle_client(self, conn, addr):
        msg = f"Received connection from (IP, PORT): {addr[0]}, {addr[1]}"
        print(msg)
        with open(self.logfile, 'a') as log:
            log.write(msg + '\n')
            packet = conn.recv(1024)
            vm_version, packet_type, message_bytes = struct.unpack('!IB5s', packet)
            message = message_bytes.decode()
            packet_size = len(message)

            if vm_version != 17:
                response = struct.pack('!IB5s', vm_version, 2, b"error")
                conn.sendall(response)
                msg = f"Received Data Version:{vm_version}, Type:{packet_type} length: {packet_size}"
                print(msg)
                log.write(msg + '\n')
                return
            else:
                response = struct.pack('!IB5s', vm_version, 1, b"hello")
                conn.sendall(response)
                msg = f"Received Data Version:{vm_version}, Type:{packet_type} length: {packet_size}"
                print(msg)
                log.write(msg + '\n')

            while True:

                #response = conn.recv(1024)
                #vm_version, message_type = struct.unpack('!IB', response)

                response = conn.recv(struct.calcsize('>III'))
                vm_version, message_type, message_bytes = struct.unpack('>III', response)
                recv_message = conn.recv(message_bytes)
                message = recv_message.decode()

                if message_type == 1:
                    msg = f"Received Data: version: {vm_version} message_type: {message_type} length: {message_bytes}"
                    print(msg)
                    log.write(msg + '\n')
                    msg = "EXECUTING SUPPORTED COMMAND: " + message
                    print(msg)
                    log.write(msg + '\n')
                    success = "success"
                    response = struct.pack('>III', vm_version, message_type, len(success)) + success.encode()
                    conn.sendall(response)
                elif message_type == 2:
                    msg = f"Received Data: version: {vm_version} message_type: {message_type} length: {message_bytes}"
                    print(msg)
                    log.write(msg + '\n')
                    msg = "EXECUTING SUPPORTED COMMAND: " + message
                    print(msg)
                    log.write(msg + '\n')
                    success = "success"
                    response = struct.pack('>III', vm_version, message_type, len(success)) + success.encode()
                    conn.sendall(response)
                else:
                    msg = f"Received Data: version: {vm_version} message_type: {message_type} length: {message_bytes}"
                    print(msg)
                    log.write(msg + '\n')
                    msg = "EXECUTING SUPPORTED COMMAND: " + message
                    print(msg)
                    log.write(msg + '\n')
                    success = "Disconnecting"
                    response = struct.pack('>III', vm_version, message_type, len(success)) + success.encode()
                    conn.sendall(response)
                    break

            msg = f"Client {addr[0]}, {addr[1]} disconnected"
            print(msg)
            log.write(msg + '\n')

    def run(self):
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        with open(self.logfile, 'a') as log:
            try:
                sock.bind(('', self.port))
            except Exception as e:
                msg = f"Error binding to {self.port}: {e}"
                print(msg)
                log.write(msg + '\n')
                return

            sock.listen()
            msg = f"Listening on {self.port}..."
            print(msg)
            log.write(msg + '\n')

            while True:
                conn, addr = sock.accept()
                client_thread = threading.Thread(target=self.handle_client, args=(conn, addr))
                client_thread.start()


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('-p', '--port', type=int, required=True, help="Server port number")
    parser.add_argument('-l', '--logfile', type=str, required=True, help="Log file name")
    args = parser.parse_args()

    server = Server(args.port, args.logfile)
    server.run()