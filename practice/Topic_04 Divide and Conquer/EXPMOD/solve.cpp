//C++ 
#include<bits/stdc++.h>
using namespace std;

uint64_t power(uint64_t x, uint64_t y, uint64_t p){
    uint64_t res = 1;
    x%=p;
    while (y > 0){
        if (y%2==1){
            res = (res*x)%p;
        }
        y>>=1;
        x = (x*x)%p;
    }
    return res%p;
}

int main(){
    uint64_t x, y;
    cin >> x >> y;

    uint64_t p = 1000000007;
    cout << power(x, y, p);
    return 0;
}
