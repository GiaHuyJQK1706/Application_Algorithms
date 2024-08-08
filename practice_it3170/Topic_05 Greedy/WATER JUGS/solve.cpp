/*
 * Solved by Gia-Huy Do
 * Using queue<Struct>, with Struct: a, b, steps
*/
#include <bits/stdc++.h>
using namespace std;

struct State {
    int a, b;
    int steps;
};

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    // check if it is possible to get c litres
    if (c > a && c > b) {
        cout << -1 << endl;
        return 0;
    }

    // perform breadth-first search to find the number of steps
    queue<State> q;
    unordered_set<int> visited;
    q.push({0, 0, 0});
    visited.insert(0);

    while (!q.empty()) {
        State s = q.front();
        q.pop();

        if (s.a == c || s.b == c) {
            cout << s.steps << endl;
            return 0;
        }

    // try filling a jug from the pump
        if (s.a < a) {
            State t = {a, s.b, s.steps+1};
            if (visited.count(t.a * 1000 + t.b) == 0) {
                q.push(t);
                visited.insert(t.a * 1000 + t.b);
            }
        }
        if (s.b < b) {
            State t = {s.a, b, s.steps+1};
            if (visited.count(t.a * 1000 + t.b) == 0) {
                q.push(t);
                visited.insert(t.a * 1000 + t.b);
            }
        }
    
        // try emptying a jug
        if (s.a > 0) {
            State t = {0, s.b, s.steps+1};
            if (visited.count(t.a * 1000 + t.b) == 0) {
                q.push(t);
                visited.insert(t.a * 1000 + t.b);
            }
        }
        if (s.b > 0) {
            State t = {s.a, 0, s.steps+1};
            if (visited.count(t.a * 1000 + t.b) == 0) {
                q.push(t);
                visited.insert(t.a * 1000 + t.b);
            }
        }
    
        // try transferring water from one jug to another
        if (s.a > 0 && s.b < b) {
            int transfer = min(s.a, b - s.b);
            State t = {s.a - transfer, s.b + transfer, s.steps+1};
            if (visited.count(t.a * 1000 + t.b) == 0) {
                q.push(t);
                visited.insert(t.a * 1000 + t.b);
            }
        }
        if (s.b > 0 && s.a < a) {
            int transfer = min(s.b, a - s.a);
            State t = {s.a + transfer, s.b - transfer, s.steps+1};
            if (visited.count(t.a * 1000 + t.b) == 0) {
                q.push(t);
                visited.insert(t.a * 1000 + t.b);
            }
        }
    }
    
  // no solution found
    cout << -1 << endl;
    return 0;
}
