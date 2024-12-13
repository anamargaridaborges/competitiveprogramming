#include <bits/stdc++.h>
#define MAXN 1010

using namespace std;

int hist[MAXN][MAXN], esq[MAXN][MAXN], dir[MAXN][MAXN];

int main () {
    int n, m;
    scanf ("%d%d", &n, &m);
    char mat[MAXN][MAXN];
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            scanf (" %c", &mat[i][j]);
            if (mat[i][j]=='.') hist[i][j] = hist[i-1][j]+1;
        }
    }
    int ans = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (mat[i][j]=='*') continue;
            esq[i][j] = j-1;
            while (hist[i][esq[i][j]]>=hist[i][j]) {
                if (j == esq[i][j]) break;
                esq[i][j] = esq[i][esq[i][j]];
            }
        }
        for (int j=m; j>=1; j--) {
            if (mat[i][j]=='*') continue;
            dir[i][j] = j+1;
            while (hist[i][dir[i][j]]>=hist[i][j]) {
                if (j == dir[i][j]) break;
                dir[i][j] = dir[i][dir[i][j]];
            }
            ans = max(ans, hist[i][j]*(dir[i][j]-esq[i][j]-1));
        }
        //for (int j=1; j<=m; j++) printf ("%d %d %d\n", hist[i][j], esq[i][j], dir[i][j]);
        //printf ("\n");
    }
    printf ("%d\n", ans);
    return 0;
}