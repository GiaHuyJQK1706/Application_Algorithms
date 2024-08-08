//JAVA 
import java.util.*; 

@SuppressWarnings({"unchecked", "deprecation"})
public class Main { 
    static boolean[] visited = new boolean[100001];
    static List<Integer>[] dinh = new ArrayList[100001];
    static int n, m;

    public static void dfs(int u) {
        System.out.print(u + " ");
        visited[u] = true;
        for (int v : dinh[u]) {
            if (!visited[v]) {
                dfs(v);
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        m = scanner.nextInt();

        for (int i = 1; i <= n; i++) {
            dinh[i] = new ArrayList<>();
        }

        for (int i = 1; i <= m; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            dinh[u].add(v);
            dinh[v].add(u);
        }

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }
    }
}
