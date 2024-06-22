import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class AddNumbersImpl extends UnicastRemoteObject implements AddNumbers {
    protected AddNumbersImpl() throws RemoteException {
        super();
    }

    @Override
    public int add(int a, int b) throws RemoteException {
        return a + b;
    }
}