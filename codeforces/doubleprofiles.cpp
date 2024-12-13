#include <bits/stdc++.h>
#define MAXN (int)1e6 + 10
 
using namespace std;
 
vector<int> adj[MAXN];
long long int pot[MAXN];
const long long int mod = (int)1e18 + 3;
map<long long int, long long int> mp;
 
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    cout<<mod<<endl;
    while (m--) {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    pot[0]=1;
    for (int i=1; i<=n; i++) pot[i] = (pot[i-1]*2)%mod;
    long long int ans = 0;
    long long int bitm[MAXN];
    for (int i=1; i<=n; i++) {
        bitm[i]=0;
        for (int j=0; j<(int)adj[i].size(); j++) {
            bitm[i] = (bitm[i]+pot[adj[i][j]])%mod;
        }
        ans += mp[bitm[i]];
        for (int j=0; j<(int)adj[i].size(); j++) {
            if (adj[i][j]>i) continue;
            if ((bitm[i]+pot[i])%mod == (bitm[adj[i][j]]+pot[adj[i][j]])%mod) {
                ans++;
            }
        }
        mp[bitm[i]]++;
    }
    cout<<ans<<endl;
    return 0;
}