# Dumpling Storage: Reserves the dumpling.

import socket
import random

def dumpling_store_process():
    port = 5001
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
        sock.bind(('localhost', port))
        sock.listen()

        print("Dumplingstore: Waiting for the orders...")

        while True:
            conn, addr = sock.accept()
            with conn:
                data = conn.recv(1024).decode()

                if data == "RESERVE DUMPLING":
                    print("\n Dumpling Storage: Reserving dumpling...")
                    
                    temp = random.randint(0, 1)
                    if temp == 0:
                        conn.sendall(b"RESERVED")
                    else:
                        conn.sendall(b"NOT RESERVED")

                elif data == "BOOK DUMPLING":
                    print("Dumpling Storage: Booking dumpling...")
                    
                    temp = random.randint(0, 1)
                    if temp == 0:
                        conn.sendall(b"COMMITTED")
                    else:
                        conn.sendall(b"NOT COMMITTED")


                elif data == "ABORT DUMPLING":
                    print("Dumpling Storage: Aborting dumpling reservation...")

if __name__ == "__main__":
    dumpling_store_process()