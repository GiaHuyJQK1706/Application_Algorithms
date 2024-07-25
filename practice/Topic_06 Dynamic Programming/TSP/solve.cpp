/*
Solved by Gia-Huy Do
Y tuong: Using dp, bitmask
*/
#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int tsp(int n, vector<vector<int>>& distances) {
    // dp[mask][i]: minimum distance to visit all cities in mask, ending in city i
    vector<vector<int>> dp(1 << n, vector<int>(n, INF));
    // Base case: starting from city 1
    dp[1][0] = 0;
    // Iterate over all possible subsets of cities
    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int u = 0; u < n; ++u) {
            // If city u is in the subset represented by mask
            if ((mask & (1 << u)) != 0) {
                for (int v = 0; v < n; ++v) {
                    // If city v is not in the subset and the distance from u to v is not zero
                    if ((mask & (1 << v)) == 0 && distances[u][v] != 0) {
                        dp[mask | (1 << v)][v] = min(dp[mask | (1 << v)][v], dp[mask][u] + distances[u][v]);
                    }
                }
            }
        }
    }

    int result = INF;
    // Iterate over all cities to find the minimum total distance
    for (int v = 1; v < n; ++v) {
        if (distances[v][0] != 0) {
            result = min(result, dp[(1 << n) - 1][v] + distances[v][0]);
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    // Input distance matrix
    vector<vector<int>> distances(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> distances[i][j];
        }
    }
    // Output the total travel distance of the optimal itinerary
    cout << tsp(n, distances) << endl;
    return 0;
}
