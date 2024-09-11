#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define N 10e5 + 4
#define W 10e5 + 4

struct Edge {
    int to, weight;
};

void dijkstra(vector<vector<Edge>>& graph, int start, vector<int>& distance) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distance[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        if (dist > distance[u]) continue;

        for (Edge& e : graph[u]) {
            int v = e.to;
            int w = e.weight;
            if (distance[v] > distance[u] + w) {
                distance[v] = distance[u] + w;
                pq.push({distance[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(0);
    int n, m; 
   
    cin >> n >> m;
    vector<vector<Edge>> graph(n + 1);
    vector<int> distance(n + 1, INF);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    int start, end; 
    cin >> start >> end;

    dijkstra(graph, start, distance);

    if (distance[end] == INF) {
        cout << -1 << endl;
    } else {
        cout << distance[end] << endl;
    }
    return 0;
}
