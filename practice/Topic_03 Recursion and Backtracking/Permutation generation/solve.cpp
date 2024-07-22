 #include<bits/stdc++.h>
using namespace std;
int n, a[21];
void print(){
    for (int i=1;i<=n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
int check(int v, int k){
    for (int i=0;i<k;i++){
        if (a[i] == v) return 0;
    }
    return 1;
}
void recall(int k){
    for (int v=1;v<=n;v++){
        if (check(v, k) == 1){
            a[k] = v;
            if (k == n){
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
    cout.tie(0);
    cin >> n;
    recall(1);
    return 0;
}
