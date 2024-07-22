#include <bits/stdc++.h>
using namespace std;

// Hàm tính mã băm của một chuỗi cho trước
int computeHash(const string& s, int m) {
    const int base = 256;  // Giá trị cơ sở cho băm
    int hash = 0;
    int power = 1;  // base^0

    // Bắt đầu từ ký tự cuối cùng và tính toán mã băm
    for (int i = s.length()-1; i >= 0; --i) {
        hash = (hash + s[i]*power) % m;
        power = (power*base) % m;  // Tính base^(i+1) % m
    }
    return hash;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<string> strings(n);

    for (int i = 0; i < n; ++i) {
        cin >> strings[i];
    }

    for (const string& s : strings) {
        cout << computeHash(s, m) << endl;
    }
    return 0;
}
