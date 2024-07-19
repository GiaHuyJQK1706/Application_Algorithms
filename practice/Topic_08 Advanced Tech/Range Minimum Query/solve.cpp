/*
Range Minimum Query
Solved by Gia-Huy Do
Y tuong: tao cau truc du lieu Segment Tree (do phuc tap O(n))
Moi truy van co do phuc tap O(logn)
=> Time Complexity: O(n + mlogn)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

// Function to build the segment tree
void buildTree(vector<int>& segTree, const vector<int>& arr, int start, int end, int node) {
    if (start == end) {
        segTree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        buildTree(segTree, arr, start, mid, 2 * node + 1);
        buildTree(segTree, arr, mid + 1, end, 2 * node + 2);
        segTree[node] = min(segTree[2 * node + 1], segTree[2 * node + 2]);
    }
}

// Function to query the segment tree
int queryTree(const vector<int>& segTree, int start, int end, int l, int r, int node) {
    if (r < start || end < l) {
        return INT_MAX;
    }
    if (l <= start && end <= r) {
        return segTree[node];
    }
    int mid = (start + end) / 2;
    int leftMin = queryTree(segTree, start, mid, l, r, 2 * node + 1);
    int rightMin = queryTree(segTree, mid + 1, end, l, r, 2 * node + 2);
    return min(leftMin, rightMin);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Build the segment tree
    vector<int> segTree(4*n);
    buildTree(segTree, arr, 0, n - 1, 0);

    int m;
    cin >> m;
    long long Q = 0;
    for (int k = 0; k < m; ++k) {
        int i, j;
        cin >> i >> j;
        Q += queryTree(segTree, 0, n - 1, i, j, 0);
    }

    cout << Q << endl;
    return 0;
}
