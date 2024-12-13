#include <bits/stdc++.h>

using namespace std;

char mat[10][10];
int lin[10];

bool check (int n) {
    for (int i=1; i<n; i++) {
        if (lin[i]==lin[n]) return false;
        if (lin[i]-i == lin[n]-n) return false;
        if (i+lin[i] == n+lin[n]) return false;
    }
    return true;
}

int rec (int n) {
    if (n == 9) {
        return 1;
    }
    int resp = 0;
    for (int i=1; i<=8; i++) {
        if (mat[i][n]!='*') {
            lin[n] = i;
            if (check(n)) resp += rec(n+1);
        }
    }
    return resp;
}

int main () {
    for (int i=1; i<=8; i++) {
        for (int j=1; j<=8; j++) scanf (" %c", &mat[i][j]);
    }
    int ans = rec(1);
    printf ("%d\n", ans);
    return 0;
}