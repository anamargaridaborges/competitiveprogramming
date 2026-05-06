#include <bits/stdc++.h>

using namespace std;

int vet[110];
int mex[110], mini[110];

int main () {
    int t;
    cin>>t;
    while (t--) {
        int n, k, q;
        cin>>n>>k>>q;
        for (int i=1; i<=n; i++) mex[i] = mini[i] = 0;
        vector<pair<int, int>> intervalos;
        for (int i=1; i<=n; i++) {
            vet[i] = -1;
        }
        for (int i=1; i<=q; i++) {
            int c, l, r;
            cin>>c>>l>>r;
            if (c == 1) {
                mini[l]++;
                mini[r+1]--;
            }
            else {
                mex[l]++;
                mex[r+1]--;
                intervalos.push_back({l, r});
            }
        }
        sort(intervalos.begin(), intervalos.end());
        for (int i=1; i<=n; i++) {
            mex[i] += mex[i-1];
            mini[i] += mini[i-1];
        }
        int aux = 0;
        for (int i=1; i<=n; i++) {
            if (mex[i] > 0 && mini[i] > 0) {
                vet[i] = (int)(1e9);
            }
            else if (mini[i] > 0 && mex[i] == 0) vet[i] = k;
            else if (mex[i] > 0 && mini[i] == 0) {
                vet[i] = aux;
                aux = (aux+1)%k;
            }
        }
        for (int i=1; i<=n; i++) {
            if (vet[i] == -1) vet[i] = (int)(1e9);
        }
        for (int i=1; i<=n; i++) cout<<vet[i]<<" ";
        cout<<endl;
    }
    return 0;
}