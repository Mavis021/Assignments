import java.rmi.Naming;
import java.util.Scanner;

public class Client {
    public static void main(String[] args) {
        try {

            Scanner scanner = new Scanner(System.in);

            System.out.println("Enter the first number: ");
            int a = scanner.nextInt();

            System.out.println("Enter the second number: ");
            int b = scanner.nextInt();

            // Lookup the remote object in the registry
            AddNumbers obj = (AddNumbers) Naming.lookup("rmi://localhost/AddNumbersService");

            
            int result = obj.add(a, b);
            System.out.println("Sum of the entered numbers: " + result);

            scanner.close();
        } catch (Exception e) {
            System.out.println("Client exception: " + e.toString());
            e.printStackTrace();
        }
    }
}
