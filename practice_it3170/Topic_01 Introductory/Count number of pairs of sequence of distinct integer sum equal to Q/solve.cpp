#include<bits/stdc++.h>
using namespace std;
int n, Q, res = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    
    cin >> n >> Q;
    vector<int> a(1000001, 0);
    for (int i=0;i<n;i++){
        int c;
        cin >> c;
        a[c] += 1;
    }
    for (int i=1;2*i<Q;i++){
        res += a[i]*a[Q-i];
    }
    cout << res;
    return 0;
}
