//C++ 
#include<bits/stdc++.h>
using namespace std;

void gc(int n, int M, vector<int> cc){
    if (n == 0){
        if (M == 0){
            for (int i=0;i<cc.size();i++){
                cout << cc[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    for (int x=1;x<=M;x++){
        if (x<=M){
            cc.push_back(x);
            gc(n-1,M-x,cc);
            cc.pop_back();
        }
    }
}

int main(){
    int n, M;
    cin >> n >> M;
    vector<int> cc;
    gc(n, M, cc);
    return 0;
}
