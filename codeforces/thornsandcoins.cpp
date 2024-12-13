#include <bits/stdc++.h>

using namespace std;

char caminho[100];
int ans[100];
int n;

int rec (int x) {
    if (ans[x]!=-1) return ans[x];
    if (x>n) return 0;
    if (x==n) {
        if (caminho[n]=='@') return 1;
        else return 0;
    }
    int at;
    if (caminho[x]=='@') at = 1;
    else at = 0;
    int ans1 = 0, ans2 = 0;
    if (x+1>n || caminho[x+1]=='*') ans1 = 0;
    else ans1 = rec(x+1);
    if (x+2>n || caminho[x+2]=='*') ans2 = 0;
    else ans2 = rec(x+2);
    return ans[x] = at + max(ans1, ans2);
}

int main () {
    int t;
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d", &n);
        for (int i=1; i<=n; i++) {
            scanf (" %c", &caminho[i]);
            ans[i]=-1;
        }
        for (int i=2; i<=n; i++) {
            if (caminho[i]=='*' && caminho[i-1]=='*') {
                for (int j=i-1; j<=n; j++) {
                    ans[i] = 0;
                }
                break;
            }
        }
        printf ("%d\n", rec(1));
    }
    return 0;
}