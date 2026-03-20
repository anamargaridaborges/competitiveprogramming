#include <iostream>
#include <map>
#include <vector>
#include <set>
#pragma GCC optimize("O3,unroll-loops")

using namespace std;

int vet[200010];
vector<int> adj[200010];
set<int> cores[200010];
int ans[200010];

void dfs (int x, int p) {
    cores[x].insert(vet[x]);
    for (int i=0; i<(int)adj[x].size(); i++) {
        int v = adj[x][i];
        if (p == v) continue;
        dfs(v, x);
        if (cores[v].size() > cores[x].size()) {
            swap(cores[v], cores[x]);
        }
        for (int y : cores[v]) cores[x].insert(y);
    }
    ans[x] = cores[x].size();
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++) {
        cin>>vet[i];
    }
    for (int i=1; i<n; i++) {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    for (int i=1; i<=n; i++) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}