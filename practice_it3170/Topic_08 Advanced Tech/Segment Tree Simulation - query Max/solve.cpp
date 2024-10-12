/*
Solved by Gia-Huy Do
Y tuong: tao cau truc du lieu Segment Tree (do phuc tap O(n))
Cac truy van deu co do phuc tap O(logn)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

class SegmentTree {
    vector<int> segTree;
    int size;

    void buildTree(const vector<int>& arr, int start, int end, int node) {
        if (start == end) {
            segTree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            buildTree(arr, start, mid, 2 * node + 1);
            buildTree(arr, mid + 1, end, 2 * node + 2);
            segTree[node] = max(segTree[2 * node + 1], segTree[2 * node + 2]);
        }
    }

    void updateTree(int start, int end, int idx, int value, int node) {
        if (start == end) {
            segTree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                updateTree(start, mid, idx, value, 2 * node + 1);
            } else {
                updateTree(mid + 1, end, idx, value, 2 * node + 2);
            }
            segTree[node] = max(segTree[2 * node + 1], segTree[2 * node + 2]);
        }
    }

    int queryTree(int start, int end, int l, int r, int node) {
        if (r < start || end < l) {
            return INT_MIN;
        }
        if (l <= start && end <= r) {
            return segTree[node];
        }
        int mid = (start + end) / 2;
        int leftMax = queryTree(start, mid, l, r, 2 * node + 1);
        int rightMax = queryTree(mid + 1, end, l, r, 2 * node + 2);
        return max(leftMax, rightMax);
    }

public:
    SegmentTree(const vector<int>& arr) {
        size = arr.size();
        segTree.resize(4 * size);
        buildTree(arr, 0, size - 1, 0);
    }

    void update(int idx, int value) {
        updateTree(0, size - 1, idx, value, 0);
    }

    int getMax(int l, int r) {
        return queryTree(0, size - 1, l, r, 0);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    SegmentTree segTree(arr);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string action;
        cin >> action;
        if (action == "get-max") {
            int l, r;
            cin >> l >> r;
            cout << segTree.getMax(l - 1, r - 1) << endl;
        } else if (action == "update") {
            int idx, value;
            cin >> idx >> value;
            segTree.update(idx - 1, value);
        }
    }

    return 0;
}
