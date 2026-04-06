#include <bits/stdc++.h>

using namespace std;

int perm[15];
int n;
vector<vector<int>> permutacoes;

void generate (int pos_at, set<int> aux, vector<int> perm_at) {
    if (pos_at == n+1) {
        permutacoes.push_back(perm_at);
        return;
    }
    set<int> aux2;
    for (int x : aux) {
        aux2.insert(x);
    }
    for (int x : aux) {
        perm_at.push_back(x);
        aux2.erase(x);
        generate(pos_at + 1, aux2, perm_at);
        aux2.insert(x);
        perm_at.pop_back();
    }
    return;
}

int main () {
    cin>>n;
    set<int> pos;
    for (int i=0; i<n; i++) {
        cin>>perm[i];
        pos.insert(i+1);
    }
    vector<int> vazio;
    generate(1, pos, vazio);
    int m = (int)permutacoes.size() - 1;
    for (int i=0; i<(int)permutacoes.size(); i++) {
        bool check = true;
        for (int j=0; j<(int)permutacoes[i].size(); j++) {
            if (permutacoes[i][j] != perm[j]) {
                check = false;
                break;
            }
        }
        if (check) {
            // achei minha resposta
            if (i == 0 && i == m) {
                // nao tem anterior e nem depois
                for (int j=0; j<n; j++) {
                    cout<<permutacoes[i][j]<<(j == n-1 ? "" : " ");
                }
                cout<<endl;
            }
            else if (i == 0) {
                // nao tem anterior
                for (int j=0; j<n; j++) {
                    cout<<permutacoes[i][j]<<(j == n-1 ? "" : " ");
                }
                cout<<endl;
                for (int j=0; j<n; j++) {
                    cout<<permutacoes[i+1][j]<<(j == n-1 ? "" : " ");
                }
                cout<<endl;
            }
            else if (i == m) {
                // nao tem dps
                for (int j=0; j<n; j++) {
                    cout<<permutacoes[i-1][j]<<(j == n-1 ? "" : " ");
                }
                cout<<endl;
                for (int j=0; j<n; j++) {
                    cout<<permutacoes[i][j]<<(j == n-1 ? "" : " ");
                }
                cout<<endl;
            }
            else {
                for (int j=0; j<n; j++) {
                    cout<<permutacoes[i-1][j]<<(j == n-1 ? "" : " ");
                }
                cout<<endl;
                for (int j=0; j<n; j++) {
                    cout<<permutacoes[i][j]<<(j == n-1 ? "" : " ");
                }
                cout<<endl;
                for (int j=0; j<n; j++) {
                    cout<<permutacoes[i+1][j]<<(j == n-1 ? "" : " ");
                }
                cout<<endl;
            }
            break;
        }
    }
}