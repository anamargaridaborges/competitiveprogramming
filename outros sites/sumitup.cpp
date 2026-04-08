#include <bits/stdc++.h>

using namespace std;

int n;

set<vector<int>> respostas;
vector<int> vet;

void rec (int pos_at, vector<int> incluso, int restante) {
    if (pos_at == n && restante != 0) return;
    else if (pos_at == n && restante == 0) {
        vector<int> aux;
        for (int i=0; i<n; i++) {
            if (incluso[i] == 1) aux.push_back(vet[i]);
        }
        respostas.insert(aux);
        return;
    }
    
    if (vet[pos_at] <= restante) {
        incluso[pos_at] = 1;
        rec(pos_at + 1, incluso, restante-vet[pos_at]);
    }
    incluso[pos_at] = 0;
    rec(pos_at + 1, incluso, restante);
    
    return;
}

int main () {
    while (true) {
        int t;
        cin>>t>>n;
        if (n == 0) break;
        respostas.clear();
        vet.clear();
        for (int i=1; i<=n; i++) {
            int x;
            cin>>x;
            vet.push_back(x);
        }
        sort(vet.begin(), vet.end());
        reverse(vet.begin(), vet.end());
        vector<int> incluso(n, 0);
        rec(0, incluso, t);
        cout<<"Sums of "<<t<<":"<<endl;
        if ((int)respostas.size() == 0) {
            cout<<"NONE"<<endl;
            continue;
        }
        for (auto it = respostas.rbegin(); it != respostas.rend(); ++it) {
            vector<int> v = *it;
            int m = (int)v.size();
            for (int j=0; j<(int)v.size(); j++) {
                if (m == 1) {
                    cout<<v[j]<<endl;
                }
                else if (j == m-1) {
                    cout<<v[j]<<endl;
                }
                else {
                    cout<<v[j]<<"+";
                }
            }
        }
    }
    return 0;
}