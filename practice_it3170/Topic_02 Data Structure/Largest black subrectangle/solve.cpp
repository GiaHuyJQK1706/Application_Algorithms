#include<bits/stdc++.h>
using namespace std;

int maxHistogramArea(vector<int>& heights) {
    stack<int> s;
    int max_area = 0;
    int index = 0;
    int n = heights.size();
    
    while (index < n) {
        if (s.empty() || heights[s.top()] <= heights[index]) {
            s.push(index++);
        } else {
            int top = s.top();
            s.pop();
            int area = heights[top] * (s.empty() ? index : index - s.top() - 1);
            max_area = max(max_area, area);
        }
    }
    
    while (!s.empty()) {
        int top = s.top();
        s.pop();
        int area = heights[top] * (s.empty() ? index : index - s.top() - 1);
        max_area = max(max_area, area);
    }
    
    return max_area;
}

int maxRectangle(vector<vector<int>>& matrix) {
    if (matrix.empty()) return 0;
    
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> heights(m, 0);
    int max_area = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == 0) {
                heights[j] = 0;
            } else {
                heights[j]++;
            }
        }
        max_area = max(max_area, maxHistogramArea(heights));
    } 
    return max_area;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }
    
    cout << maxRectangle(matrix) << endl;
    return 0;
}
