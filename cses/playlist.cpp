#include <bits/stdc++.h>
#define MAXN 2*((int)1e5+5)

using namespace std;

map<int, int> freq;

int main () {
    int n;
    int vet[MAXN];
    scanf ("%d", &n);
    for (int i=1; i<=n; i++) {
        scanf ("%d", &vet[i]);
    }
    int l = 1;
    int ans = 0;
    for (int r=1; r<=n; r++) {
        freq[vet[r]]++;
        if (freq[vet[r]] == 1) {
            ans = max(ans, r-l+1);
        }
        else {
            while (freq[vet[r]]>1) {
                freq[vet[l]]--;
                l++;
            }
        }
    }
    printf ("%d\n", ans);
    return 0;
}