//JAVA 
import java.util.*;
import java.math.*;

@SuppressWarnings({"unchecked", "deprecation"})
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        BigInteger a = sc.nextBigInteger();
        BigInteger b = sc.nextBigInteger();
        BigInteger ans = a.add(b);
        
        System.out.print(ans);
    }
}
