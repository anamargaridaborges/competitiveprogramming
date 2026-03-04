#include <bits/stdc++.h>
#define int long long

using namespace std;

int vet[200010], seg[800010], aux[200010];

void build (int node, int l, int r) {
    if (l == r) {
        seg[node] = aux[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    seg[node] = seg[2*node] + seg[2*node+1];
    return;
}

void update (int node, int l, int r, int k) {
    if (l == r) {
        seg[node] = 0;
        return;
    }
    int mid = (l+r)/2;
    if (k <= mid) {
        update(2*node, l, mid, k);
    }
    else {
        update(2*node+1, mid+1, r, k);
    }
    seg[node] = seg[2*node] + seg[2*node+1];
    //cout<<l<<" "<<r<<" "<<seg[node]<<endl;
    return;
}

int query (int node, int l, int r, int l0, int r0) {
    if (l >= l0 && r <= r0) return seg[node];
    if (r < l0 || l > r0) return 0;
    int mid = (l+r)/2;
    return query(2*node, l, mid, l0, r0) + query(2*node+1, mid+1, r, l0, r0);
}

int32_t main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++) {
        cin>>vet[i];
        aux[i] = 1;
    }
    build(1, 1, n);
    for (int i=1; i<=n; i++) {
        int q;
        cin>>q;
        int l = 1, r = n, mid;
        int ans = -1;
        while (l <= r) {
            mid = (l+r)/2;
            int soma_mid = query(1, 1, n, 1, mid);
            if (soma_mid >= q) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        cout<<vet[ans]<<" ";
        update(1, 1, n, ans);
    }
    cout<<endl;
    return 0;
}