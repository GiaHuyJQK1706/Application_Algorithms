//C++ 
#include<bits/stdc++.h>
using namespace std;
int n, m, a[101];
void print(){
    for (int i=1;i<=m;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
int check(int v, int k){
    if (v <= a[k-1]){
        return 0;
    }
    return 1;
}
void recall(int k){     //Recusive function (Back-tracking)
    for (int v=1;v<=n;v++){
        if(check(v, k) == 1){
            a[k] = v;
            if (k == m){
                print();
            } else {
                recall(k+1);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(nullptr);
    cin >> m >> n;
    recall(1);
    return 0;
}
