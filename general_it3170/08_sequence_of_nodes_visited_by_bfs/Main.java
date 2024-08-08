//JAVA 
import java.util.*; 

@SuppressWarnings({"unchecked", "deprecation"})
public class Main { 
    public static List<Integer> bfs(int start, List<List<Integer>> adj, boolean[] visited) {
        Queue<Integer> q = new LinkedList<>();
        List<Integer> result = new ArrayList<>();
        q.add(start);
        visited[start] = true;

        while (!q.isEmpty()) {
            int node = q.poll();
            result.add(node);

            for (int neighbor : adj.get(node)) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.add(neighbor);
                }
            }
        }

        return result;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        List<List<Integer>> adj = new ArrayList<>(n + 1);

        for (int i = 0; i <= n; i++) {
            adj.add(new ArrayList<>());
        }

        for (int i = 0; i < m; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        for (int i = 1; i <= n; i++) {
            Collections.sort(adj.get(i));
        }

        boolean[] visited = new boolean[n + 1];
        List<Integer> bfs_result = new ArrayList<>();

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                List<Integer> partial_result = bfs(i, adj, visited);
                bfs_result.addAll(partial_result);
            }
        }

        for (int i = 0; i < bfs_result.size(); i++) {
            if (i > 0) System.out.print(" ");
            System.out.print(bfs_result.get(i));
        }
        System.out.println();
    }
}
