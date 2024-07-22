//C++ 
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
const int maxN = 999 + 100;
const int Mod = 1e9 + 7;
int a[maxN][maxN], m, n, r, c, d[maxN][maxN];
// a[maxN][maxN] đánh dấu một ô đã xét hay chưa
// d[maxN][maxN] lưu độ dài đường đi từ ô xuất phát
int dx[] = {1, 0, -1, 0},
    dy[] = {0, 1, 0, -1};
queue<ii> qe; // lưu các ô lân cận sẽ được xét

int solve() {
    qe.push(ii(r, c));
    d[r][c] = 0;
    a[r][c] = 1;
    while (!qe.empty()) {
        ii u = qe.front();
        qe.pop();
        for (int i = 0; i < 4; i++) {
            int x = dx[i] + u.first;
            int y = dy[i] + u.second;
            if (x < 1 || x > m || y < 1 || y > n)
                return d[u.first][u.second] + 1;
            if (a[x][y] != 1) {
                d[x][y] = d[u.first][u.second] + 1;
                qe.push(ii(x, y));
                a[x][y] = 1;
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> m >> n >> r >> c;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
            
    cout << solve();
    return 0;
}
