#include<bits/stdc++.h>
using namespace std;

int countPairs(vector<int>& arr, int M) {
    unordered_set<int> seen;
    int count = 0;
    for (int num : arr) {
        if (seen.find(M - num) != seen.end()) {
            count++;
        }
        seen.insert(num);
    }
    return count;
}

int main() {
    int n, M;
    cin >> n >> M;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << countPairs(arr, M) << endl;
    return 0;
}
