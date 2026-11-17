#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll vet[50];
vector<ll> freq1, freq2;

void backtracking (ll soma, int l, int r, int idx, bool eh_um) {
    if (idx == r + 1) {
        if (eh_um) freq1.push_back(soma);
        else freq2.push_back(soma);
        return;
    }
    backtracking(soma, l, r, idx+1, eh_um);
    backtracking(soma + vet[idx], l, r, idx+1, eh_um);
}

int idx_igual(ll y, bool menor) {
    int l = 0, r = (int)freq2.size()-1, mid;
    int idx = -1;
    while (l <= r) {
        mid = (l+r)/2;
        if (freq2[mid] == y) {
            idx = mid;
            if (menor) r = mid - 1;
            else l = mid + 1;
        }
        else if (freq2[mid] > y) r = mid - 1;
        else l = mid + 1;
    }
    return idx;
}

int32_t main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin>>n>>x;
    for (int i=1; i<=n; i++) {
        cin>>vet[i];
    }
    backtracking(0ll, 1, n/2, 1, true);
    backtracking(0ll, (n/2) + 1, n, (n/2) + 1, false);
    sort(freq1.begin(), freq1.end());
    sort(freq2.begin(), freq2.end());
    ll ans = 0;
    for (ll y : freq1) {
        // achar qtd de elementos iguais a x-y em freq2
        if (y > x) continue;
        int menor_idx = idx_igual(x-y, true), maior_idx = idx_igual(x-y, false);
        if (menor_idx == -1) continue;
        ans += maior_idx - menor_idx + 1;
    }
    cout<<ans<<endl;
    return 0;
}