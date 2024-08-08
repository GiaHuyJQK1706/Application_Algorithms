//JAVA 
/*
 * Solved by Gia-Huy Do
 */
import java.util.*; 

@SuppressWarnings({"unchecked", "deprecation"})
public class Main { 
    static boolean[] visited;
    static ArrayList<Integer>[] adj;
    static int n, m;
    public static void dfs(int u){
        visited[u] = true;
        for (int v : adj[u]){
            if (!visited[v]){
                dfs(v);
            }
        }
    }
    public static int dem_lien_thong(){
        int rs = 0;
        for (int i=1;i<=n;i++){
            if (!visited[i]){
                dfs(i);
                rs++;
            }
        }
        return rs;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        visited = new boolean[1000001];
        adj = new ArrayList[1000001];
        for (int i = 1; i <= n; i++) {
            adj[i] = new ArrayList<>();
        }
        for (int i=1;i<m;i++){
            int u = sc.nextInt();
            int v = sc.nextInt();
            adj[u].add(v);
            adj[v].add(u);
        }
        System.out.println(dem_lien_thong());
    }
}
