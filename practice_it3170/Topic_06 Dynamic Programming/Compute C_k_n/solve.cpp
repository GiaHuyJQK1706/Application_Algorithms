/*
Solved by Gia-Huy Do
C(k, n) = C(k-1, n-1) + C(k, n-1)
C(0, n) = C(n, n) = 1 
*/
#include <bits/stdc++.h> 
using namespace std;
#define Mod 1000000007;
int dp[1000][1000];
int k, n;

int main() { 
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(0);
    
    cin >> k >> n;
    dp[0][0] = 1;
    for (int i=1;i<=999;i++){
        dp[0][i] = 1;
        dp[i][i] = 1;
    }
    
    for (int i=2;i<=n;i++){
        for (int j=1;j<i;j++){
            dp[j][i] = (dp[j-1][i-1] + dp[j][i-1])%Mod;
        }
    }
    
    cout << dp[k][n];
    
    return 0;
}
