import args.*;

public class Main {

    public static void main(String[] args) {
        try {
            Args arg = new Args("l,p#,d*", args);
            boolean logging = arg.getBoolean('l');
            int port = arg.getInt('p');
            String directory = arg.getString('d');
            System.out.printf("Boolean %b\n", logging);
            System.out.printf("Integer %d\n", port);
            System.out.printf("Directory %s\n", directory);
            // executeApplicaton(logging, port, directory);
        } catch (ArgsException e) {
            System.out.printf("Argument error: %s\n", e.errorMessage());
        }
    }

}
