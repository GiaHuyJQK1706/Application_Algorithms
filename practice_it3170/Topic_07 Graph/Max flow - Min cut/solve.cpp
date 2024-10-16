/*
 * Solved by Gia-Huy Do
 * Y tuong: dung thuat toan Edmonds-Karp tim duong tang luong
*/
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
vector<vector<int>> capacity, adj;

//Tim duong tang luong thong qua BFS
int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = s;
    queue<pair<int, int>> q;
    q.push({s, INF});
    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next] > 0) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t) return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}

int maxFlow(int s, int t, int n) {
    int flow = 0;
    vector<int> parent(n + 1);
    while (int new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;

        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
}

int main() {
    int N, M;
    cin >> N >> M;
    int s, t;
    cin >> s >> t;

    capacity.assign(N + 1, vector<int>(N + 1, 0)); //Capacity: Luu luong toi da cho canh noi tu u den v
    adj.assign(N + 1, vector<int>());

    for (int i = 0; i < M; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        capacity[u][v] += c;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << maxFlow(s, t, N) << endl;
    return 0;
}
