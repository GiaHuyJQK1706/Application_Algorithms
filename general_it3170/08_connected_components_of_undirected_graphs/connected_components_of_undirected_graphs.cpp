//C++ 
#include<bits/stdc++.h>
using namespace std;
bool visited[100001];
vector<int> adj[100001];
int n, m;
void dfs(int u){
    visited[u] = true;
    for (int v : adj[u]){
        if (!visited[v]){
            dfs(v);
        }
    }
}
int dem_lien_thong(){
    int rs = 0;
    for (int i=1;i<=n;i++){
        if (!visited[i]){
            dfs(i);
            ++rs;
        }
    }
    return rs;
}
int main(){
    cin >> n >> m;
    for (int i=1;i<=m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << dem_lien_thong();
    return 0;
}
