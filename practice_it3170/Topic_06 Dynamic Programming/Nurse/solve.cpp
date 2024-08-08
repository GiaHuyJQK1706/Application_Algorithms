/*
* Solved by Gia-Huy Do
* Y tuong
    dp1[0] = dp1[1] = 1
    dp2[k1] = 1
    Voi i tu k1+1 den n:
        dp1[i] = dp2[i-1]
        dp2[i] = dp1[i-j] voi dieu kien k1<=j<=k2 va i-j >= 0
*/
#include<bits/stdc++.h>
using namespace std;
#define MAX 1001
int dp1[MAX];
int dp2[MAX];

int assign_to_nurse(int n, int k1, int k2){
    memset(dp1, 0, MAX);
    memset(dp2, 0, MAX);
    dp1[0] = 1;
    dp1[1] = 1;
    dp2[k1] = 1;
    for (int i=k1+1;i<=n;i++){
        dp1[i] = dp2[i-1];
        dp2[i] = 0;
        for (int j=k1;j<=k2;j++){
            if (i-j>=0){
                dp2[i] += dp1[i-j];
            }
        }
    }
    return dp1[n] + dp2[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, K1, K2;
    cin >> N >> K1 >> K2;
    cout << assign_to_nurse(N, K1, K2);
    return 0;
}
