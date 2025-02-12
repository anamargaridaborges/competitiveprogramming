#include <bits/stdc++.h>
#define int long long
#define MAXN (int) (3e3 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)

using namespace std;

typedef struct Func {
    int a;
    int b;
    int sub;
    int val (int x) {
        return a*x +b;
    }
}Func;

deque<Func> retas[MAXN];

void update(Func curr) {
    int tam = retas[curr.sub].size();
    while (tam>1 && ((retas[curr.sub][tam-2].b-retas[curr.sub][tam-1].b)*(curr.a-retas[curr.sub][tam-2].a)) >= ((retas[curr.sub][tam-2].b-curr.b)*(retas[curr.sub][tam-1].a-retas[curr.sub][tam-2].a)))
        retas[curr.sub].pop_back(), tam--;
    retas[curr.sub].push_back(curr);
}

int query(int x, int sub) {
    while (retas[sub].size()>1 && retas[sub][0].val(x) >= retas[sub][1].val(x))
        retas[sub].pop_front();
    return retas[sub].front().val(x);
}

int dp[MAXN][MAXN];
int sum[MAXN];

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin>>n>>k;
    int v[MAXN];
    for (int i=1; i<=n; i++) cin>>v[i];
    for (int i=1; i<=n; i++) sum[i] = sum[i-1] + v[i];
    Func curr;
    for (int i=1; i<=n; i++) {
        dp[i][1] = sum[i]*sum[i];
        curr.a = -2*sum[i];
        curr.b = sum[i]*sum[i] + dp[i][1];
        curr.sub = 1;
        update(curr);
    }
    for (int j=2; j<=k; j++) {
        for (int i=2; i<=n; i++) {
            dp[i][j] = query(sum[i], j-1) + sum[i]*sum[i];
            curr.a = -2*sum[i];
            curr.b = sum[i]*sum[i] + dp[i][j];
            curr.sub = j;
            update(curr);
        }
    }
    cout<<dp[n][k]<<endl;
    return 0;
}