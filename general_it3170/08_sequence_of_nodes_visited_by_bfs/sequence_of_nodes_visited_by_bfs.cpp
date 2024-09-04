//C++ 
#include <bits/stdc++.h>
using namespace std;

// Ham thuc hien BFS bat dau tu dinh start
vector<int> bfs(int start, vector<vector<int>> &adj, vector<bool> &visited) {
    queue<int> q;
    vector<int> result;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        // Duyet cac dinh ke va them vao hang doi
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        sort(adj[i].begin(), adj[i].end());
    }

    vector<bool> visited(n + 1, false);
    vector<int> bfs_result;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            vector<int> partial_result = bfs(i, adj, visited);
            bfs_result.insert(bfs_result.end(), partial_result.begin(), partial_result.end());
        }
    }

    for (size_t i = 0; i < bfs_result.size(); ++i) {
        if (i > 0) cout << " ";
        cout << bfs_result[i];
    }
    cout << endl;

    return 0;
}
