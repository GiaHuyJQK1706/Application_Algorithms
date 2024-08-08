//C++ 
#include<bits/stdc++.h>
using namespace std;

vector<string> rs;
int a[1000001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, L;
    cin >> n >> L;
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    for (int i=0;i<n;i++){
        string curr = to_string(a[i]);
        while(curr.size() != L){
            curr = '0' + curr;
        }
        rs.push_back(curr);
    }
    for (string s : rs){
        cout << s << endl;
    }
    return 0;
}
