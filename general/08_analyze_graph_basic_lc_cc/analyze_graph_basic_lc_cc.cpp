//C++ 
/*
Note: code nay an duoc 11/20 testcase
5/20 testcase bi WA
3/20 testcase bi TLE
1/20 testcase bi MRE
*/
#include <bits/stdc++.h>
using namespace std;

// Cau truc de luu thong tin diem
struct Point {
    string id;
    int x, y;
};

// Cau truc de luu thong tin canh
struct Segment {
    string id;
    string p1, p2;
};

// Ham DFS de tim cac thanh phan lien thong
void dfs(const string &point, map<string, vector<string>> &adj, map<string, bool> &visited) {
    visited[point] = true;
    for (const string &neighbor : adj[point]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

// Ham DFS de tim chu trinh dai nhat
int longestCycleFrom(const string &point, map<string, vector<string>> &adj, map<string, bool> &visited) {
    stack<pair<string, int>> st;
    st.push({point, 0});
    map<string, int> maxLength;
    maxLength[point] = 0;
    int maxCycleLength = 0;

    while (!st.empty()) {
        auto [current, length] = st.top();
        st.pop();
        visited[current] = true;

        for (const string &neighbor : adj[current]) {
            if (neighbor == point) {
                maxCycleLength = max(maxCycleLength, length + 1);
            } else if (!visited[neighbor]) {
                st.push({neighbor, length + 1});
                maxLength[neighbor] = max(maxLength[neighbor], length + 1);
            }
        }
    }
    return maxCycleLength;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(nullptr);
    
    map<string, Point> points;
    map<string, Segment> segments;
    map<string, vector<string>> adj;

    // Doc du lieu cua cac diem
    string line;
    while (getline(cin, line) && line != "#") {
        stringstream ss(line);
        Point p;
        ss >> p.id >> p.x >> p.y;
        points[p.id] = p;
    }

    // Doc du lieu cua cac canh
    while (getline(cin, line) && line != "#") {
        stringstream ss(line);
        Segment s;
        ss >> s.id >> s.p1 >> s.p2;
        segments[s.id] = s;
        adj[s.p1].push_back(s.p2);
        adj[s.p2].push_back(s.p1);
    }

    // Xu ly cac truy van
    while (getline(cin, line) && line != "###") {
        if (line == "?number_points") {
            cout << points.size() << endl;
        } else if (line == "?number_segments") {
            cout << segments.size() << endl;
        } else if (line == "?connected_components") {
            int components = 0;
            map<string, bool> visited;
            for (const auto &p : points) {
                if (!visited[p.first]) {
                    dfs(p.first, adj, visited);
                    components++;
                }
            }
            cout << components << endl;
        } else if (line.rfind("?longest_cycle_from", 0) == 0) {
            string pointID = line.substr(line.find(" ") + 1);
            map<string, bool> visited;
            cout << longestCycleFrom(pointID, adj, visited) << endl;
        }
    }

    return 0;
}
