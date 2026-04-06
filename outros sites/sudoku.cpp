#include <bits/stdc++.h>

using namespace std;

int mat[15][15];
int ans[15][15];
int n;

bool rec (int x, int y, int aux[15][15][15]) {
    if (x == (n*n + 1) && y == n*n) {
        for (int i=1; i<=n*n; i++) {
            for (int j=1; j<=n*n; j++) {
                if (!ans[i][j]) return false;
            }
        }
        return true;
    }
    if (mat[x][y] != 0) {
        ans[x][y] = mat[x][y];
        return rec((y%(n*n) == 0 ? x+1 : x), (y%(n*n) == 0 ? 1 : y+1), aux);
    }
    for (int i=1; i<=n*n; i++) {
        // testar valores
        int aux2[15][15][15];
        if (aux[x][y][i]) continue;
        // cout<<x<<" "<<y<<" "<<i<<endl;
        for (int l=1; l<=9; l++) {
            for (int j=1; j<=9; j++) {
                for (int k=1; k<=9; k++) aux2[l][j][k] = aux[l][j][k];
            }
        }
        ans[x][y] = i;
        for (int j=1; j<=n*n; j++) {
            aux2[x][j][i] = 1;
            aux2[j][y][i] = 1;
        }
        for (int k=((x-1)/n)*n + 1; k<=ceil(((double)x/(double)n))*n; k++) {
                for (int l=((y-1)/n)*n + 1; l<=ceil(((double)y/(double)n))*n; l++) {
                aux2[k][l][i] = 1;
            }
        }
        bool check = rec((y%(n*n) == 0 ? x+1 : x), (y%(n*n) == 0 ? 1 : y+1), aux2);
        if (check) {
            return true;
        }
        ans[x][y] = 0;
    }
    return false;
}

int main () {
    int nao_pode[15][15][15];
    cin>>n;
    while (true) {
        for (int i=1; i<=9; i++) {
            for (int j=1; j<=9; j++) {
                for (int k=1; k<=9; k++) nao_pode[i][j][k] = 0;
            }
        }
        for (int i=1; i<=n*n; i++) {
            for (int j=1; j<=n*n; j++) {
                cin>>mat[i][j];
            }
        }
        for (int i=1; i<=n*n; i++) {
            for (int j=1; j<=n*n; j++) {
                if (mat[i][j] != 0) continue;
                for (int k=1; k<=n*n; k++) {
                    if (mat[i][k] != 0) {
                        nao_pode[i][j][mat[i][k]] = 1;
                    }
                    if (mat[k][j] != 0) {
                        nao_pode[i][j][mat[k][j]] = 1;
                    }
                }
                for (int k=((i-1)/n)*n + 1; k<=ceil(((double)i/(double)n))*n; k++) {
                    for (int l=((j-1)/n)*n + 1; l<=ceil(((double)j/(double)n))*n; l++) {
                        if (mat[k][l] != 0) {
                            nao_pode[i][j][mat[k][l]] = 1;
                        }
                    }
                }
            }
        }
        if (rec(1, 1, nao_pode)) {
            for (int i=1; i<=n*n; i++) {
                for (int j=1; j<=n*n; j++) {
                    cout<<ans[i][j]<<(j == n*n ? "" : " ");
                }
                cout<<endl;
            }
        }
        else cout<<"NO SOLUTION"<<endl;
        if (cin>>n) {
            cout<<endl;
        }
        else {
            break;
        }
        // string s;
        // getline(cin, s);
    }
}