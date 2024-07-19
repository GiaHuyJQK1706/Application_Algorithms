//C++ 
#include<bits/stdc++.h>
using namespace std;
bool cpr(pair<int, int> A, pair<int, int> B){
    if (A.second < B.second) return true;
    return false;
}
int main(){
    int n;
    cin >> n;
    int rs=0;
    vector<pair<int, int>> a(n);
    for (int i=0;i<n;i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(),a.end(),cpr);
    int cnt = 1;
    int enddt = a[0].second;
    for (int i=1;i<a.size();i++){
        if (a[i].first > enddt){
            cnt++;
            enddt = a[i].second;
        }
    }
    cout << cnt;
    return 0;
}
