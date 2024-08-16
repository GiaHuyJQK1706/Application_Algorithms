//C++ 
#include <bits/stdc++.h>

using namespace std;

int findLongestIncreasingSubsequence(const vector<int>& sequence) {
    int n = sequence.size();
    vector<int> lis(n, 1);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (sequence[i] > sequence[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }

    int max_length = 0;
    for (int i = 0; i < n; ++i) {
        if (lis[i] > max_length) {
            max_length = lis[i];
        }
    }

    return max_length;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(0);
    
    int n;
    cin >> n;

    vector<int> sequence(n);

    for (int i = 0; i < n; ++i) {
        cin >> sequence[i];
    }

    int longestIncreasingSubsequenceLength = findLongestIncreasingSubsequence(sequence);

    cout << longestIncreasingSubsequenceLength << endl;

    return 0;
}
