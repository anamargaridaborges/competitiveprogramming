#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> permutacoes;
int n;

void generate (int pos_at, set<int> aux, vector<int> perm_at) {
    if (pos_at == n+1) {
        permutacoes.push_back(perm_at);
        return;
    }
    set<int> aux2;
    for (int v : aux) aux2.insert(v);
    for (int v : aux) {
        aux2.erase(v);
        perm_at.push_back(v);
        generate(pos_at + 1, aux2, perm_at);
        aux2.insert(v);
        perm_at.pop_back();
    }
    return;
}

int main () {
    cin>>n;
    set<int> pos;
    for (int i=1; i<=n; i++) pos.insert(i);
    vector<int> vazio;
    generate(1, pos, vazio);
    for (vector<int> v : permutacoes) {
        for (int i = 0; i<n; i++) {
            cout<<v[i]<<(i == n-1 ? "" : " ");
        }
        cout<<endl;
    }
    return 0;
}