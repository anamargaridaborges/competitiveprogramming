#include <bits/stdc++.h>

using namespace std;

int primo[1000010], fat_c[1000010];

void crivo() {
    for (int i=2; i<=1000000; i++) {
        if (primo[i]) continue;
        primo[i] = i;
        for (int j=2*i; j<=1000000; j+=i) primo[j] = i;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    crivo();
    int n, k;
    cin>>n>>k;
    vector<pair<int, int>> fat;
    while (k != 1) {
        int aux = 0;
        int at = primo[k];
        while (k % at == 0) {
            aux++;
            k = k/at;
        }
        fat.push_back({at, aux});
    }
    for (int i=1; i<=n; i++) {
        int c;
        cin>>c;
        while (c != 1) {
            int aux = 0;
            int at = primo[c];
            while (c % at == 0) {
                aux++;
                c = c/at;
            }
            fat_c[at] = max(fat_c[at], aux);
        }
    }
    bool check = true;
    for (auto[at, aux] : fat) {
        if (fat_c[at] < aux) check = false;
    }
    if (check) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}