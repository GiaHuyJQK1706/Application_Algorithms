#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];  
int tin[MAXN], low[MAXN];  
bool visited[MAXN];  
bool isArti[MAXN];
int timer, arti, bridge;

void dfs(int u, int parent) {
    visited[u] = true;
    tin[u] = low[u] = ++timer;
    int child = 0;
    for (int v : adj[u]) {
        if (v == parent) continue;
        if (visited[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u]) { bridge++; }
            if (low[v] >= tin[u] && parent != -1) { isArti[u] = true; }
            child++;
        }
    }
    if (parent == -1 && child > 1) { isArti[u] = true; }
}

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int X, Y;
        cin >> X >> Y;
        adj[X].push_back(Y);
        adj[Y].push_back(X);
    }

    timer = 0;
    arti = 0;
    bridge = 0;

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs(i, -1);
        }
    }

    for (int i = 1; i <= N; i++) {
        if (isArti[i]) {
            arti++;
        }
    }
    cout << arti << " " << bridge << endl;
    return 0;
}
