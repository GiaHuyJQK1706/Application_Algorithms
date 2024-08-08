//C++ 
#include<bits/stdc++.h>
using namespace std;
bool visited[100001];
vector<int> dinh[100001];
int n, m;
void dfs(int u){
    cout << u << " ";
    visited[u] = true;
    for (int v : dinh[u]){
        if (!visited[v]){
            dfs(v);
        }
    }
}
int main(){
    cin >> n >> m;
    for (int i=1;i<=m;i++){
        int u, v;
        cin >> u >> v;
        dinh[u].push_back(v);
        dinh[v].push_back(u);
    }
    for (int i=1;i<=n;i++){
        if (!visited[i]){
            dfs(i);
        }
    }
    return 0;
}
