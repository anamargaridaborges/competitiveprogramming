#include <bits/stdc++.h>
#define MAXN (int)(3e5+10)

using namespace std;

const int inf = 1e9+1;

int main () {
    int t;
    scanf ("%d", &t);
    while (t--) {
        int n, k;
        scanf ("%d%d", &n, &k);
        char str[MAXN];
        int vet[MAXN];
        str[0] = 'R';
        for (int i=1; i<=n; i++) scanf (" %c", &str[i]);
        for (int i=1; i<=n; i++) scanf ("%d", &vet[i]);
        int blocos = 0;
        for (int i=1; i<=n; i++) {
            if (str[i] == 'B' && str[i-1] == 'R') blocos++;
        }
        if (blocos<=k) {
            printf ("0\n");
            continue;
        }
        //blocos = blocos-k;
        int maxi = 0;
        vector<int> bloc;
        for (int i=1; i<=n; i++) {
            if (str[i] == 'B' && str[i-1] == 'R') {
                if (maxi != 0) bloc.push_back(maxi);
                maxi = vet[i];
            }
            else if (str[i] == 'B' && str[i-1] == 'B') {
                maxi = max(maxi, vet[i]);
            }
        }
        bloc.push_back(maxi);
        sort(bloc.begin(), bloc.end());
        int ans = 0;
        for (int i=0; i<blocos-k; i++) {
            ans = max(ans, bloc[i]);
        }
        bloc.clear();
        bool check = true;
        maxi = 0;
        for (int i=1; i<=n; i++) {
            if (str[i] == 'R' && check) continue;
            if (str[i] == 'B' && check) check = false;
            if (str[i] == 'R' && str[i-1] == 'B') {
                if (maxi != 0) bloc.push_back(maxi);
                maxi = vet[i];
            }
            else if (str[i] == 'R' && str[i-1] == 'R') maxi = max(maxi, vet[i]);
        }
        if (str[n] == 'B') bloc.push_back(maxi);
        int ans2 = 0;
        sort(bloc.begin(), bloc.end());
        for (int i=0; i<blocos-k; i++) {
            ans2 = max(ans2, bloc[i]);
        }
        printf ("%d\n", min(ans, ans2));
    }
    return 0;
}