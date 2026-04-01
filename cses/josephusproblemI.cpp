#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    cin>>n;
    queue<int> at;
    for (int i=1; i<=n; i++) at.push(i);
    bool mata = false;
    while (!at.empty()) {
        int v = at.front();
        at.pop();
        if (at.empty()) {
            cout<<v<<endl;
            break;
        }
        if (!mata) {
            at.push(v);
        }
        else cout<<v<<" ";
        mata = !mata;
    }
    return 0;
}