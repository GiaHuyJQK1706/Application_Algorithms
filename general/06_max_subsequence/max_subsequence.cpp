#include <bits/stdc++.h>

using namespace std;

int dp[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    
    dp[0] = a[0];
    
    for(int i = 1; i < n; ++i) {
        dp[i] = (dp[i-1] > 0) ? dp[i-1] + a[i] : a[i];
    }
    
    cout << dp[n-1] << endl;
    
    return 0;
}