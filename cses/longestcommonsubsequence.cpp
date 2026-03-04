#include <bits/stdc++.h>

using namespace std;

int vet1[1010], vet2[1010];
int dp[1010][1010];

int lcs (int n, int m) {
    if (n == 0 || m == 0) return 0;
    if (dp[n][m] != -1) return dp[n][m];
    if (vet1[n] == vet2[m]) {
        return dp[n][m] = 1 + lcs(n-1, m-1);
    }
    else {
        return dp[n][m] = max(lcs(n, m-1), lcs(n-1, m));
    }
}

int main () {
    int n, m;
    cin>>n>>m;
    for (int i=1; i<=n; i++) cin>>vet1[i];
    for (int i=1; i<=m; i++) cin>>vet2[i];
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) dp[i][j] = -1;
    }
    cout<<lcs(n, m)<<endl;
    int aux1 = n, aux2 = m;
    stack<int> ans;
    while (aux1 != 0 && aux2 != 0) {
        if (vet1[aux1] == vet2[aux2]) {
            ans.push(vet1[aux1]);
            aux1--, aux2--;
        }
        else {
            if (dp[aux1][aux2] == dp[aux1-1][aux2]) {
                aux1--;
            }
            else {
                aux2--;
            }
        }
    }
    while (!ans.empty()) {
        int t = ans.top();
        ans.pop();
        cout<<t<<" ";
    }
    cout<<endl;
    return 0;
}