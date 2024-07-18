//C++ 
#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int dp[1000001];
int main(){
    int n, l1, l2;
    cin >> n >> l1 >> l2;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    dp[1] = a[1];
    for (int i=2;i<=l1;i++){
        if (a[i] > dp[i-1]){
            dp[i] = a[i];
        } else {
            dp[i] = dp[i-1];
        }
    }
    for (int i=l1+1;i<=n;i++){
        dp[i] = max(dp[i-1],a[i] + dp[i-l1]);
    }
    cout << dp[n];
    return 0;
}
