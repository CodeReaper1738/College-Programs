import argparse
import socket
import struct

parser = argparse.ArgumentParser()
parser.add_argument("-p", "--port", type=int, help="the port number to listen on")
parser.add_argument("-l", "--log", help="the location of the log file")
args = parser.parse_args()

if not args.port or not args.log:
    print("Usage: lightserver -p <PORT> -l <LOG FILE LOCATION>")
    exit(1)

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    sock.bind(('', args.port))
except Exception as e:
    print(f"Error binding to {args.port}: {e}")
    exit(1)

sock.listen()
with open(args.log, 'a') as log_file:
    while True:
        print("Waiting for a connection...")

        client_socket, client_address = sock.accept()

        data = b''
        while len(data) < 12:
            packet = sock.recv(12 - len(data))
            if not packet:
                print("Error: connection closed by server")
                sock.close()
                exit(1)
            data += packet

        version, message_type, message_length = struct.unpack("!III", data)

        if version != 17:
            error_msg = f"VERSION MISMATCH: received version {version} but expected 17"
            print(error_msg)
            log_file.write(error_msg + '\n')
            client_socket.close()
            continue

        if message_type == 1:
            print("Received LIGHTON packet")
            log_file.write("Received LIGHTON packet\n")
        elif message_type == 2:
            print("Received LIGHTOFF packet")
            log_file.write("Received LIGHTOFF packet\n")
        else:
            print("Unknown packet type")
            log_file.write("Unknown packet type\n")
            client_socket.close()
            continue

        received_message = b''
        while len(received_message) < message_length:
            packet = client_socket.recv(message_length - len(received_message))
            if not packet:
                break
            received_message += packet

        if received_message.decode() == "DISCONNECT":
            client_socket.close()
            continue

        response = struct.pack("!III7s", 17, 3, 7, b"SUCCESS")
        client_socket.sendall(response)

        if received_message.decode() == "QUIT":
            break

    sock.close()