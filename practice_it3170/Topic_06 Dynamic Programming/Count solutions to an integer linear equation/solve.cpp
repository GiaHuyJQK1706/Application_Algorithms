/*
* Solved by Gia-Huy Do
* Phan tich de bai:
    So nghiem nguyen duong (X1,... Xn) cua phuong trinh a_1X_1 + ... + a_nX_n = M chính la so nghiem nguyen khong am (X1,... Xn) cua phuong trinh a_1X_1 + ... + a_nX_n = M - (a_1 + a_2 + ... + a_n)
* Y tuong:
    Lap trinh tim so bo nghiem nguyen khong am (X1,... Xn) cua phuong trinh a_1X_1 + ... + a_nX_n = M - (a_1 + a_2 + ... + a_n) = M'
    Tao mang a[] = {a_1,... ,a_n}
    Tao mang dp[] co M+1 phan tu (Khoi tao tat ca phan tu bang 0)
    Truong hop co so: dp[0] = 1 (Vi phuong trinh a_1X_1 + ... + a_nX_n = 0 co 1 nghiem duy nhat (0,... 0) )
    Xet i lan luot tu 1 den n, ta co: 
        dp[j] = dp[j] + dp[j - a_i] (Voi j la tat ca cac gia tri xet lan luot tu a_i den M')
        (dp[j] la so nghiem (X1,... Xi) cua phuong trinh a_1X_1 + ... +a_iX_i = j)
    Sau khi xet het xong, dp[M'] la ket qua can tim
* Do phuc tap O(n*(M-a_1-...-a_n)) ~ O(n*M)
*/
#include <bits/stdc++.h>
using namespace std;

int countSol(int n, int M, vector<int>& a) {
    vector<int> dp(M + 1, 0);
    dp[0] = 1;
    int tong = 0;
    for (int i:a){
        tong+=i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = a[i]; j <= M-tong; j++) {
            dp[j] += dp[j - a[i]];
        }
    }
    return dp[M-tong];
}

int main() {
    int n, M;
    cin >> n >> M;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << countSol(n, M, a) << endl;
    return 0;
}
