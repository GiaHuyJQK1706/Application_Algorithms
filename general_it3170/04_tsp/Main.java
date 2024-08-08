//JAVA 
import java.util.*; 

@SuppressWarnings({"unchecked", "deprecation"})
public class Main { 
    static int tsp(int pos, int mask, int[][] dist, int[][] dp) {
        int n = dist.length;
        if (mask == (1 << n) - 1) {
            // All cities have been visited, return the distance to the starting city
            return dist[pos][0];
        }
        
        if (dp[pos][mask] != -1) {
            return dp[pos][mask];
        }
        
        int ans = Integer.MAX_VALUE;
        for (int city = 0; city < n; city++) {
            if ((mask & (1 << city)) == 0) {
                // If the city has not been visited
                int newAns = dist[pos][city] + tsp(city, mask | (1 << city), dist, dp);
                ans = Math.min(ans, newAns);
            }
        }
        
        return dp[pos][mask] = ans;
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        
        int[][] dist = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = scanner.nextInt();
            }
        }
        
        int[][] dp = new int[n][1 << n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (1 << n); j++) {
                dp[i][j] = -1;
            }
        }
        
        System.out.println(tsp(0, 1, dist, dp));
    }
}
