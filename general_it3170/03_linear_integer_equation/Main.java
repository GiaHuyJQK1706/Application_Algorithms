//JAVA 
import java.util.*; 

@SuppressWarnings({"unchecked", "deprecation"})
public class Main { 
    static void gc(int n, int M, List<Integer> cc) {
        if (n == 0) {
            if (M == 0) {
                for (int i = 0; i < cc.size(); i++) {
                    System.out.print(cc.get(i) + " ");
                }
                System.out.println();
            }
            return;
        }
        for (int x = 1; x <= M; x++) {
            if (x <= M) {
                cc.add(x);
                gc(n - 1, M - x, cc);
                cc.remove(cc.size() - 1);
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int M = scanner.nextInt();
        List<Integer> cc = new ArrayList<>();
        gc(n, M, cc);
    }
}