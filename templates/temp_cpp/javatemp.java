import java.util.*;
import java.io.*;

class Main {

    void run() {
        //Scanner in = new Scanner(System.in);
        MyReader in = new MyReader();
        String str;
    }

    public static void main(String args[]) {
        new Main().run();
    }
    
    void debug(Object...x) {
        System.out.println(Arrays.deepToString(x));
    }
}

class MyReader {
    BufferedReader br = new BufferedReader (
            new InputStreamReader (System.in));
    StringTokenizer in;
    String next() {
        try {
            while (in == null || !in.hasMoreTokens()) {
                // Read a new line and split it into tokens
                in = new StringTokenizer(br.readLine());
            }
            // return next token
            return in.nextToken();
        } catch (Exception e) {
            // EOF
            return null;
        }
    }
    // Transform the tokens into other types
    int nextInt() {
        return Integer.parseInt(next());
    }
}
