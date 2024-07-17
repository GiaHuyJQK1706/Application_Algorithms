//C++ 
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> X(n);
    vector<int> Y(m);
    
    for (int i = 0; i < n; i++) {
        cin >> X[i];
    }
    
    for (int i = 0; i < m; i++) {
        cin >> Y[i];
    }
    
    // Create two 1D DP arrays
    vector<int> dpPrev(m + 1, 0);
    vector<int> dpCurr(m + 1, 0);
    
    // Fill the DP table using only two rows
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dpCurr[j] = dpPrev[j - 1] + 1;
            } else {
                dpCurr[j] = max(dpPrev[j], dpCurr[j - 1]);
            }
        }
        // Swap dpPrev and dpCurr
        swap(dpPrev, dpCurr);
    }
    
    // The length of the longest common subsequence
    cout << dpPrev[m] << endl;
    
    return 0;
}
