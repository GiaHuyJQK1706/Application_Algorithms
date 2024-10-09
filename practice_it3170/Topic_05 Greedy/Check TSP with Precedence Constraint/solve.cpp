/*
 * Solved by Gia-Huy Do
 * Y tuong: Kiem tra cac rang buoc tuan tu, sau do tinh toan quang duong kieu brute force
*/
#include <bits/stdc++.h>
using namespace std;

bool is_feasible_route(const vector<int>& route, const vector<pair<int, int>>& precedence) {
    unordered_map<int, int> position;
    for (int i = 0; i < route.size(); ++i) {
        position[route[i]] = i;
    }
    for (const auto& p : precedence) {
        int i = p.first, j = p.second;
        if (position[i] > position[j]) {
            return false;
        }
    }
    return true;
}

int compute_travel_distance(const vector<int>& route, const vector<vector<int>>& distances) {
    int total_distance = 0;
    for (int i = 0; i < route.size() - 1; ++i) {
        total_distance += distances[route[i] - 1][route[i + 1] - 1];
    }
    total_distance += distances[route.back() - 1][route[0] - 1]; 
    return total_distance;
}

int main() {
    int n;
    cin >> n;
    vector<int> route(n);
    for (int i = 0; i < n; ++i) {
        cin >> route[i];
    }
    vector<vector<int>> distances(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> distances[i][j];
        }
    }
    int m;
    cin >> m;
    vector<pair<int, int>> precedence(m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        precedence[i] = {u, v};
    }

    if (!is_feasible_route(route, precedence)) {
        cout << -1 << endl;
    } else {
        cout << compute_travel_distance(route, distances) << endl;
    }
    return 0;
}
