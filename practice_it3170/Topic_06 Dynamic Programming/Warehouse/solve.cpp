/*
 * Solved by Gia-Huy Do
 * dp[i][t] la luong hang hoa lon nhat khi xe dung o tram i va xe da di duoc khoang thoi gian t
 * Do phuc tap trung binh O(N*T*D)
*/
#include <bits/stdc++.h>
using namespace std;

int dp[1001][101];
int N, T, D;
int res = 0;

int main() {
    cin >> N >> T >> D;
    vector<int> a(N), t(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> t[i];
    }

    for (int i = 0; i < N; ++i) {
        if (t[i] <= T) {
            dp[i][t[i]] = a[i];
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int time = 0; time <= T; ++time) {
            if (dp[i][time] == 0) continue;
            for (int j = i + 1; j <= i + D && j < N; ++j) {
                if (time + t[j] <= T) {
                    dp[j][time + t[j]] = max(dp[j][time + t[j]], dp[i][time] + a[j]);
                }
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int time = 0; time <= T; ++time) {
            res = max(res, dp[i][time]);
        }
    }
    cout << res << endl;
    return 0;
}
