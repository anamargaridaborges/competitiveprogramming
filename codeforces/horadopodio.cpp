#include <bits/stdc++.h>

using namespace std;

map<string, int> g, p, b;
priority_queue<pair<pair<int, int>, pair<int, string>>> pq;

void three_best() {
    pair<pair<int, int>, pair<int, string>> best[5];
    set<string> countries;
    for (int i=1; i<=3; i++) {
        auto[x, y] = pq.top();
        pq.pop();
        if (countries.find(y.second) != countries.end()) {
            // ja contabilizei esse
            i--;
            continue;
        }
        best[i] = {x, y};
        cout<<y.second<<" ";
        countries.insert(y.second);
    }
    for (int i=1; i<=3; i++) {
        pq.push(best[i]);
    }
    cout<<endl;
}

int main () {
    int n, q;
    cin>>n>>q;
    for (int i=1; i<=n; i++) {
        string s;
        int x, y, z;
        cin>>s>>x>>y>>z;
        cin.ignore();
        g[s] = x;
        p[s] = y;
        b[s] = z;
        pq.push({{x, y}, {z, s}});
    }
    three_best();
    while (q--) {
        string s;
        int x;
        cin>>s>>x;
        if (x == 1) {
            g[s]++;
        }
        if (x == 2) {
            p[s]++;
        }
        if (x == 3) {
            b[s]++;
        }
        pq.push({{g[s], p[s]}, {b[s], s}});
        three_best();
    }
}