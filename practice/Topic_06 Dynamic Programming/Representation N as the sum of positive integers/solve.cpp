/*
Solved by Gia-Huy Do
Y tuong: tao ham truy hoi
Goi so cach tach so N thanh tong cua k chu so khac nhau la P(k, N). Khi do:
P(k, N) = P(k-1, N-1) + P(k, N-k)
Voi truong hop co so: P(1, N) = 1, P(N, N) = 1;
*/

#include <bits/stdc++.h> 
using namespace std;
#define Mod 1000000007;
int n, res = 0;
int dp[1001][1001]; //Tao mang dp 2 chieu luu giu cac ket qua cua P(x, y)
int main() { 
    cin >> n;
    for (int i=1;i<=n;i++){
        dp[1][i] = 1;
        dp[i][i] = 1;
    }
    for(int i=3;i<=n;i++){
        for (int j=2;j<i;j++){
            dp[j][i] = (dp[j-1][i-1] + dp[j][i-j])%Mod;
        }
    }
    for (int i=1;i<=n;i++){
        res = (res + dp[i][n])%Mod;
    }
    cout << res;
    return 0;
}
