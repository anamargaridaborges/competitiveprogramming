#include <bits/stdc++.h>
#define int long long
#define MAXN (int) (2e5 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)

using namespace std;

typedef struct Func {
    int a;
    int b;
    int val (int x) {
        return a*x + b;
    }
}Func;

deque<Func> retas;

void update (Func curr) {
    int tam = retas.size();
    while (tam>1 && ((retas[tam-2].b-retas[tam-1].b)*(curr.a-retas[tam-2].a)) >= ((retas[tam-2].b-curr.b)*(retas[tam-1].a-retas[tam-2].a)))
        retas.pop_back(), tam--;
    retas.push_back(curr);
}

int query (int x) {
    while (retas.size()>1 && retas[0].val(x) >= retas[1].val(x)) 
        retas.pop_front();
    return retas.front().val(x);
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x;
    cin>>n>>x;
    int s[MAXN], f[MAXN];
    for (int i=1; i<=n; i++) {
        cin>>s[i];
    }
    for (int i=1; i<=n; i++) {
        cin>>f[i];
    }
    int dp[MAXN];
    dp[1] = x*s[1];
    Func curr;
    curr.a = f[1];
    curr.b = dp[1];
    update(curr);
    for (int i=2; i<=n; i++) {
        dp[i] = min(query(s[i]), x*s[i]);
        curr.a = f[i];
        curr.b = dp[i];
        update(curr);
    }
    cout<<dp[n]<<endl;
    return 0;
}