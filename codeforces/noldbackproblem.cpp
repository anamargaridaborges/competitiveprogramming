#include <bits/stdc++.h>

using namespace std;

int primo[1010];

int main () {
    int n, k;
    scanf ("%d%d", &n, &k);
    vector<int> primos;
    for (int i=2; i<=n; i++) {
        if (primo[i]==0) {
            primos.push_back(i);
            for (int j=i*2; j<=n; j+=i) primo[j] = 1; 
        }
    }
    int ans = 0;
    for (int i=0; i<(int)primos.size(); i++) {
        for (int j=0; j<(int)primos.size()-1; j++) {
            if (primos[i]==primos[j]+primos[j+1]+1) {
                ans++;
                break;
            }
        }
    }
    if (ans>=k) printf ("YES\n");
    else printf ("NO\n");
    return 0;
}