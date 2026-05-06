#include <bits/stdc++.h>

using namespace std;

int mini[800010], maxi[800010];
int vet[200010];

void build (int node, int l, int r) {
    if (l == r) {
        mini[node] = vet[l];
        maxi[node] = vet[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    maxi[node] = max(maxi[2*node], maxi[2*node+1]);
    mini[node] = min(mini[2*node], mini[2*node+1]);
    return;
}

int query_min (int node, int l, int r, int l0, int r0) {
    if (l >= l0 && r <= r0) return mini[node];
    if (l > r0 || r < l0) return (int)(1e9);
    int mid = (l+r)/2;
    return min(query_min(2*node, l, mid, l0, r0), query_min(2*node+1, mid+1, r, l0, r0));
}

int query_max (int node, int l, int r, int l0, int r0) {
    if (l >= l0 && r <= r0) return maxi[node];
    if (l > r0 || r < l0) return 0;
    int mid = (l+r)/2;
    return max(query_max(2*node, l, mid, l0, r0), query_max(2*node+1, mid+1, r, l0, r0));
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        for (int i=1; i<=n; i++) cin>>vet[i];
        build(1, 1, n);
        bool check = true;
        for (int i=2; i<=n; i++) {
            if (query_min(1, 1, n, 1, i-1) > query_max(1, 1, n, i, n)) check = false;
        }
        if (check) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}