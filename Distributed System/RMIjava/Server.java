import java.rmi.Naming;
import java.rmi.registry.LocateRegistry;

public class Server {
    public static void main(String[] args) {
        try {
            // Create and export a registry on port 1099
            LocateRegistry.createRegistry(1098);

            // Create an instance of AddNumbersImpl
            AddNumbersImpl obj = new AddNumbersImpl();

            // Bind the remote object's stub in the registry
            Naming.rebind("rmi://localhost/AddNumbersService", obj);

            System.out.println("Server is ready.");
        } catch (Exception e) {
            System.out.println("Server exception: " + e.toString());
            e.printStackTrace();
        }
    }
}

