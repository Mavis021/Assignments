# Delivery: Reserves a delivery agent

import socket
import random

def delivery_process():
    port = 5002
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
        sock.bind(('localhost', port))
        sock.listen()

        print("Delivery: Waiting for the orders...")

        while True:
            conn, addr = sock.accept()
            with conn:
                data = conn.recv(1024).decode()

                if data == "RESERVE AGENT":
                    print("\n Delivery: Reserving delivery agent...")
                    # Simulate reservation success
                    
                    temp = random.randint(0, 1)
                    if temp == 0:
                        conn.sendall(b"RESERVED")
                    else:
                        conn.sendall(b"NOT RESERVED")

                elif data == "BOOK AGENT":
                    print("Delivery: Booking delivery agent...")
                    
                    temp = random.randint(0, 1)
                    if temp == 0:
                        conn.sendall(b"COMMITTED")
                    else:
                        conn.sendall(b"NOT COMMITTED")

                elif data == "ABORT DELIVERY AGENT":
                    print("Delivery: Aborting delivery agent reservation...")

if __name__ == "__main__":
    delivery_process()