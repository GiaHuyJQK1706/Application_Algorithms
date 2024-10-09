#include <bits/stdc++.h>
using namespace std;
int a[1001][4];
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
    }
    int min_x = min(a[0][0], a[0][2]), min_y = min(a[0][1], a[0][3]), max_x = max(a[0][0], a[0][2]), max_y = max(a[0][1], a[0][3]);
    for (int i=1;i<n;i++) {
        min_x = min(min_x, min(a[i][0], a[i][2]));
        max_x = max(max_x, max(a[i][0], a[i][2]));
        min_y = min(min_y, min(a[i][1], a[i][3]));
        max_y = max(max_y, max(a[i][1], a[i][3]));
    }
    cout << (max_x - min_x)*(max_y - min_y);
    return 0;
}
