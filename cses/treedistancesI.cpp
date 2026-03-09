#include <bits/stdc++.h>

using namespace std;

vector<int> adj[200010];
pair<int, int> max1[200010], max2[200010];
int ans[200010];

int dfs (int x, int p) {
    if (x != 1 && (int)adj[x].size() == 1) return 0;
    pair<int, int> aux1 = {0, 0}, aux2 = {0, 0};
    for (auto u : adj[x]) {
        if (u == p) continue;
        int aux = dfs(u, x) + 1;
        if (aux > aux1.first) {
            aux2 = aux1;
            aux1 = {aux, u};
        }
        else if (aux == aux1.first) {
            aux2 = aux1;
            aux1 = {aux, u};
        }
        else {
            if (aux2.first < aux) {
                aux2 = {aux, u};
            }
        }
    }
    max1[x] = aux1, max2[x] = aux2;
    return aux1.first;
}

void calc (int x, int p) {
    if (x != 1) {
        if (max1[p].second == x) {
            // pego o max2
            if (max2[p].first + 1 > max1[x].first) {
                max1[x] = {max2[p].first + 1, p};
            } 
            else if (max2[p].first + 1 == max1[x].first) {
                max2[x] = {max2[p].first + 1, p};
            }
            else {
                if (max2[p].first + 1 > max2[x].first) {
                    max2[x] = {max2[p].first + 1, p};
                }
            }
        }
        else {
            // pego o max1
            if (max1[p].first + 1 > max1[x].first) {
                max1[x] = {max1[p].first + 1, p};
            } 
            else if (max1[p].first + 1 == max1[x].first) {
                max2[x] = {max1[p].first + 1, p};
            }
            else {
                if (max1[p].first + 1 > max2[x].first) {
                    max2[x] = {max1[p].first + 1, p};
                }
            }
        }
    }
    for (auto u : adj[x]) {
        if (u == p) continue;
        calc(u, x);
    }
    return;
}

int main () {
    int n;
    cin>>n;
    for (int i=1; i<n; i++) {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    calc(1, 0);
    for (int i=1; i<=n; i++) cout<<max1[i].first<<" ";
    cout<<endl;
    return 0;
}