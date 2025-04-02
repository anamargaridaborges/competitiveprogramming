#include <bits/stdc++.h>
#define int long long
#define MAXN (int)(1e4 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int)(1e9 + 7)
#define BASE 37
#define MAXL 20
#define INF (int)(1LL<<30)
#define PI 3.14159265359
#define EPS (1e-9)
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

int comp[MAXN], tam[MAXN];

int pai (int x) {
    if (comp[x]==x) return x;
    return comp[x] = pai(comp[x]);
}

void join (int a, int b) {
    a = pai(a);
    b = pai(b);
    if (a==b) return;
    if (tam[a]>tam[b]) {
        tam[a] += tam[b];
        comp[b] = a;
    }
    else {
        tam[b] += tam[a];
        comp[a] = b;
    }
    return;
}

int32_t main()
{_

    int n;
    cin>>n;
    int vet[MAXN];
    for (int i=1; i<=n; i++) {
        cin>>vet[i];
        comp[i]=i;
        tam[i]=1;
    }
    int igual[MAXN];
    for (int i=1; i<=n; i++) {
        join(i, vet[i]);
        igual[i]=0;
    }
    int ans = 0;
    for (int i=1; i<=n; i++) {
        int x = pai(i);
        if (igual[x]==0) {
            ans++;
            igual[x]=1;
        }
    }
    cout<<ans<<endl;
    return 0;

}