#include <bits/stdc++.h>
#define ll long long
#define MAXN (int)(1e6 + 5)
    
using namespace std;
    
typedef struct Func {
    ll a;
    ll b;
}Func;
    
Func retas[MAXN];
int tam, ini;
    
double calc (Func um, Func dois) {
    return (double)(dois.b-um.b)/(double)(um.a-dois.a);
}
    
void update (Func curr) {
    while (tam-ini>1 && (calc(retas[tam-1], retas[tam-2]) > calc(curr, retas[tam-1])))
        tam--;
    retas[tam].a = curr.a;
    retas[tam].b = curr.b;
    tam++;
}
    
ll query (ll x) {
    while (tam-ini>1 && retas[ini].a*x+retas[ini].b<=retas[ini+1].a*x+retas[ini+1].b)
        ini++;
    return retas[ini].a*x+retas[ini].b;
}
    
/*bool comp (pair<pair<ll, ll>, ll> a, pair<pair<ll, ll>, ll> b) {
    return a.first.first<=b.first.second;
}*/
    
int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    vector<pair<pair<ll, ll>, ll>> rec(n);
    for (int i=0; i<n; i++) {
        cin>>rec[i].first.first>>rec[i].first.second>>rec[i].second;
    }
    sort(rec.begin(), rec.end());
    ll dp[MAXN];
    Func curr;
    curr.a = 0;
    curr.b = 0;
    update(curr);
    ll ans = 0;
    for (int i=0; i<n; i++) {
        ll x, y, a;
        x = rec[i].first.first, y = rec[i].first.second, a = rec[i].second;
        dp[i] = x*y - a+query(-y);
        curr.a = x;
        curr.b = dp[i];
        update(curr);
        ans = max(ans, dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}