# Orders: Acts as the coordinator

import socket

def orders_process():

    # Defining ports for Dumping Storage and Delivery
    port_storage = 5001
    port_delivery = 5002

    # Prepare phase - reserve
    print("Orders: Starting the prepare phase - Reserve")

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as storage_sock, \
    socket.socket(socket.AF_INET, socket.SOCK_STREAM) as delivery_sock:

        # Connecting to Dumping Storage
        storage_sock.connect(('localhost', port_storage))
        storage_sock.sendall(b'RESERVE DUMPLING')
        data = storage_sock.recv(1024)
        storage_response = data.decode()

        # Connecting to Delivery
        delivery_sock.connect(('localhost', port_delivery))
        delivery_sock.sendall(b'RESERVE AGENT')
        data = delivery_sock.recv(1024)
        delivery_response = data.decode()

        # If both the responses are positive, then commit
        if storage_response == "RESERVED" and delivery_response == "RESERVED":
            print("Orders: Reserve phase successful")
            print("Orders: Starting the commit phase")

            commit_status = commit(port_storage, port_delivery)
            if commit_status:
                print("Orders: Commit phase successful")
                print("Orders: Order placed successfully")
            else:
                print("Orders: Order failed during commit phase")
                abort(port_storage, port_delivery)
        else:
            print("Orders: Reservation failed. Aborting the transaction.")
            abort(port_storage, port_delivery)
        

def commit(storage_port, delivery_port):
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as storage_sock, \
    socket.socket(socket.AF_INET, socket.SOCK_STREAM) as delivery_sock:

        # Connecting to Dumping Storage to commit
        storage_sock.connect(('localhost', storage_port))
        storage_sock.sendall(b'BOOK DUMPLING')
        data = storage_sock.recv(1024)
        storage_response = data.decode()

        # Connecting to Delivery
        delivery_sock.connect(('localhost', delivery_port))
        delivery_sock.sendall(b'BOOK AGENT')
        data = delivery_sock.recv(1024)
        delivery_response = data.decode()

        # If both the responses are positive, then commit
        if storage_response == "COMMITTED" and delivery_response == "COMMITTED":
            return True
        else:
            return False
        
def abort(storage_port, delivery_port):
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as storage_sock, \
    socket.socket(socket.AF_INET, socket.SOCK_STREAM) as delivery_sock:

        # Connecting to Dumping Storage to abort
        storage_sock.connect(('localhost', storage_port))
        storage_sock.sendall(b'ABORT DUMPLING')


        # Connecting to Delivery to abort
        delivery_sock.connect(('localhost', delivery_port))
        delivery_sock.sendall(b'ABORT DELIVERY AGENT')

        print("Orders: Transaction aborted")

if __name__ == "__main__":
    orders_process()