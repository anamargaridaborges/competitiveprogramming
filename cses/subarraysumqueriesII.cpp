#include <bits/stdc++.h>
#define int long long
#define iiii pair<pair<int, int>, pair<int, int>>

using namespace std;

int vet[200010], pref[800010], suf[800010], sum[800010], seg[800010];

void build (int node, int l, int r) {
    if (l == r) {
        pref[node] = max(0ll, vet[l]);
        suf[node] = max(0ll, vet[l]);
        sum[node] = vet[l];
        seg[node] = max(0ll, vet[l]);
        return;
    }
    int mid = (l+r)/2;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    sum[node] = sum[2*node] + sum[2*node+1];
    pref[node] = max(pref[2*node], sum[2*node]+pref[2*node+1]);
    suf[node] = max(suf[2*node+1], sum[2*node+1]+suf[2*node]);
    seg[node] = max(suf[2*node] + pref[2*node+1], max(seg[2*node], seg[2*node+1]));
    return;
}

iiii query (int node, int l, int r, int l0, int r0) {
    //{{pref, suf}, {sum, seg}}
    if (l > r0 || r < l0) return {{0, 0}, {0, 0}};
    if (l >= l0 && r <= r0) {
        return {{pref[node], suf[node]}, {sum[node], seg[node]}};
    }
    int mid = (l+r)/2;
    iiii aux1 = query(2*node, l, mid, l0, r0), aux2 = query(2*node+1, mid+1, r, l0, r0);
    int pref_at = max(aux1.first.first, aux1.second.first + aux2.first.first);
    int suf_at = max(aux2.first.second, aux2.second.first + aux1.first.second);
    int sum_at = aux2.second.first + aux1.second.first;
    int seg_at = max(aux1.first.second+aux2.first.first, max(aux1.second.second, aux2.second.second));
    return {{pref_at, suf_at}, {sum_at, seg_at}};
}

int32_t main () {
    int n, q;
    cin>>n>>q;
    for (int i=1; i<=n; i++) cin>>vet[i];
    build(1, 1, n);
    while (q--) {
        int a, b;
        cin>>a>>b;
        iiii ans = query(1, 1, n, a, b);
        cout<<ans.second.second<<endl;
    }
    return 0;
}