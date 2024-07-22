//C++ 
#include<bits/stdc++.h>
using namespace std;
int n, a[21];
void print(){
    for (int i=1;i<=n;i++){
        cout << a[i];
    }
    cout << endl;
}
void recall(int k){
    for (int v=0;v<=1;v++){
        a[k] = v;
        if (k == n){
            print();
        } else {
            recall(k+1);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    recall(1);
    return 0;
}
