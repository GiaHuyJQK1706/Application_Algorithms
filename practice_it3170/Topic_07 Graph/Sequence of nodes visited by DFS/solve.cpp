//C++ 
#include<bits/stdc++.h>
using namespace std;
bool visited[10001];
vector<int> adj[10001];
int n, m;
void dfs(int u){
    cout << u << " ";
    visited[u] = true;
    for (int v : adj[u]){
        if (!visited[v]){
            dfs(v);
        }
    }
}
void liet_ke(){
    for (int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1;i<=n;i++){
        sort(adj[i].begin(), adj[i].end());
    }
    liet_ke();
    return 0;
}
