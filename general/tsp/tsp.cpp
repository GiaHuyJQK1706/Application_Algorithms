//C++ 
#include <bits/stdc++.h>

using namespace std;

int tsp(int pos, int mask, vector<vector<int>>& dist, vector<vector<int>>& dp) {
    int n = dist.size();
    if(mask == (1 << n) - 1) {
        // All cities have been visited, return the distance to the starting city
        return dist[pos][0];
    }
    
    if(dp[pos][mask] != -1) {
        return dp[pos][mask];
    }
    
    int ans = INT_MAX;
    for(int city = 0; city < n; city++) {
        if((mask & (1 << city)) == 0) {
            // If the city has not been visited
            int newAns = dist[pos][city] + tsp(city, mask | (1 << city), dist, dp);
            ans = min(ans, newAns);
        }
    }
    
    return dp[pos][mask] = ans;
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> dist(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }
    
    vector<vector<int>> dp(n, vector<int>(1 << n, -1));
    
    cout << tsp(0, 1, dist, dp) << endl;
    
    return 0;
}
