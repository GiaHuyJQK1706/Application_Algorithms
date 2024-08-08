import java.util.*; 

@SuppressWarnings({"unchecked", "deprecation"})
public class Main { 
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int[] a = new int[n];
        
        for (int i = 0; i < n; ++i) {
            a[i] = scanner.nextInt();
        }
        
        int[] dp = new int[n];
        dp[0] = a[0];
        int res = dp[0];
        
        for (int i = 1; i < n; ++i) {
            dp[i] = (dp[i-1] > 0) ? dp[i-1] + a[i] : a[i];
            res = Math.max(res, dp[i]);
        }
        
        System.out.println(res);
        scanner.close();
    }
}
