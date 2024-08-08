//C++ 
#include <bits/stdc++.h> 

using namespace std;

string incrementString(const string& str) {
    string result = str;
    int i = result.size() - 1;
    while (i >= 0 && result[i] == '9') {
        result[i] = '0';
        i--;
    }
    if (i >= 0) {
        result[i]++;
    } else {
        result = "1" + result;
    }
    return result;
}

int main() {
    int n, L, m;
    cin >> n >> L >> m;

    set<string> existing_keys;
    for (int i = 0; i < n; ++i) {
        string key;
        cin >> key;
        existing_keys.insert(key);
    }

    vector<string> all_keys(existing_keys.begin(), existing_keys.end());
    string current_key = string(L - 1, '0') + '1';  // Start from "000001"

    while (m > 0) {
        if (existing_keys.find(current_key) == existing_keys.end()) {
            all_keys.push_back(current_key);
            m--;
        }
        current_key = incrementString(current_key);
    }

    sort(all_keys.begin(), all_keys.end());

    for (const string& key : all_keys) {
        cout << key << endl;
    }

    return 0;
}
