#include <bits/stdc++.h>
using namespace std;

void add(string a, string b, string &result) {
    int carry = 0;
    int i = 0;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    while (i < a.length() || i < b.length() || carry) {
        int sum = carry;
        if (i < a.length()) sum += a[i] - '0';
        if (i < b.length()) sum += b[i] - '0';
        result.push_back((sum % 10) + '0');
        carry = sum / 10;
        i++;
    }

    reverse(result.begin(), result.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string a, b, result;
    
    cin >> a >> b;
    add(a, b, result);
    cout << result << endl;

    return 0;
}
