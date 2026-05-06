#include <bits/stdc++.h>

using namespace std;

int vet[200010];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--) {
        int n, k;
        cin>>n>>k;
        set<int> s, aux;
        for (int i=1; i<=n; i++) {
            cin>>vet[i];
            s.insert(vet[i]);
            aux.insert(vet[i]);
        }
        sort(vet+1, vet+n+1);
        bool funciona = true;
        vector<int> b;
        for (int i=1; i<=n; i++) {
            if (s.find(vet[i]) == s.end()) continue;
            for (int j=vet[i]; j<=k; j+=vet[i]) {
                if (aux.find(j) != aux.end()) {
                    s.erase(j);
                }
                else {
                    funciona = false;
                    break;
                }
            }
            if (funciona) b.push_back(vet[i]);
            else break;
        }
        if (funciona) {
            cout<<(int)b.size()<<endl;
            for (int x : b) cout<<x<<" ";
            cout<<endl;
        }
        else cout<<-1<<endl;
    }
    return 0;
}