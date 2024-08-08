//JAVA 
import java.util.*; 

@SuppressWarnings({"unchecked", "deprecation"})
public class Main { 
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        int[] X = new int[n];
        int[] Y = new int[m];
        
        for (int i = 0; i < n; i++) {
            X[i] = scanner.nextInt();
        }
        
        for (int i = 0; i < m; i++) {
            Y[i] = scanner.nextInt();
        }
        
        // Create two 1D DP arrays
        int[] dpPrev = new int[m + 1];
        int[] dpCurr = new int[m + 1];
        
        // Fill the DP table using only two rows
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (X[i - 1] == Y[j - 1]) {
                    dpCurr[j] = dpPrev[j - 1] + 1;
                } else {
                    dpCurr[j] = Math.max(dpPrev[j], dpCurr[j - 1]);
                }
            }
            // Swap dpPrev and dpCurr
            int[] temp = dpPrev;
            dpPrev = dpCurr;
            dpCurr = temp;
        }
        
        // The length of the longest common subsequence
        System.out.println(dpPrev[m]);
    }
}
