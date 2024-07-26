//C++ 
#include <bits/stdc++.h>
using namespace std;

// Định nghĩa cấu trúc của một cạnh trong đồ thị
struct Edge {
    int u, v, weight;
};

// Định nghĩa cấu trúc của một tập hợp con (disjoint set)
struct DisjointSet {
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.assign(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int findSet(int u) {
        if (u != parent[u]) {
            parent[u] = findSet(parent[u]);
        }
        return parent[u];
    }

    void unionSets(int u, int v) {
        int rootU = findSet(u);
        int rootV = findSet(v);

        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else {
                parent[rootU] = rootV;
                if (rank[rootU] == rank[rootV]) {
                    rank[rootV]++;
                }
            }
        }
    }
};

// Hàm so sánh cạnh để sắp xếp theo trọng số tăng dần
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

int kruskal(vector<Edge>& edges, int n) {
    sort(edges.begin(), edges.end(), compareEdges);

    DisjointSet disjointSet(n);
    int minWeight = 0;

    for (const Edge& edge : edges) {
        int rootU = disjointSet.findSet(edge.u);
        int rootV = disjointSet.findSet(edge.v);

        if (rootU != rootV) {
            disjointSet.unionSets(edge.u, edge.v);
            minWeight += edge.weight;
        }
    }

    return minWeight;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    cout << kruskal(edges, n) << endl;
    return 0;
}
