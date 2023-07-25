import argparse
import socket
import struct

def receive_data(sock, length):
    data = b''
    while len(data) < length:
        packet = sock.recv(length - len(data))
        if not packet:
            print("Error: connection closed by server")
            sock.close()
            exit(1)
        data += packet
    return data

parser = argparse.ArgumentParser()
parser.add_argument("-s", "--server", help="the server IP address")
parser.add_argument("-p", "--port", type=int, help="the port number to connect to")
parser.add_argument("-l", "--log", help="the location of the log file")
args = parser.parse_args()

if not args.server or not args.port or not args.log:
    print("Usage: lightclient -s <SERVER IP> -p <PORT> -l <LOG FILE LOCATION>")
    exit(1)

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    sock.connect((args.server, args.port))
except Exception as e:
    print(f"Error connecting to {args.server}:{args.port}: {e}")
    exit(1)

print("Sending Hello Packet")
sock.sendall(struct.pack("!III6s", 17, 1, 6, b"hello"))

data = receive_data(sock, 12)

version, message_type, message_length = struct.unpack("!III", data)

if version == 17:
    print("VERSION ACCEPTED")
else:
    print("VERSION MISMATCH")
    with open(args.log, 'a') as log_file:
        log_file.write(f"VERSION MISMATCH: received version {version} but expected 17\n")

if version == 17:
    received_message = receive_data(sock, message_length)
    received_message = received_message.decode()
    print("Received Message" + received_message)

    command_type = input("Enter command (1 for LIGHTON, 2 for LIGHTOFF): ")
    if command_type not in ["1", "2"]:
        print("Invalid command")
        sock.close()
        exit(1)
    command_type = int(command_type)

    if command_type == 1:
        command = "LIGHTON".encode()
        print("Sending command LIGHTON")
    elif command_type == 2:
        command = "LIGHTOFF".encode()
        print("Sending command LIGHOFF")

    command_length = len(command)
    sock.sendall(struct.pack("!III", 17, 2, command_length) + command)

    data = receive_data(sock, 12)

    version, message_type, message_length = struct.unpack("!III", data)

    if version == 17:
        received_message = receive_data(sock, message_length)
        received_message = received_message.decode()
        print("Received Message: " + received_message)
        with open(args.log, 'a') as log_file:
            log_file.write(f"Received Message: {received_message}\n")
    else:
        print("VERSION MISMATCH")
        with open(args.log, 'a') as log_file:
            log_file.write(f"VERSION MISMATCH: received version {version} but expected 17\n")
            sock.close()
            exit(1)
disconnect = input("Do you want to disconnect? (y/n): ")

if disconnect.lower() == "y":
    sock.sendall(struct.pack("!III10s", 17, 4, 10, b"DISCONNECT"))
    sock.close()