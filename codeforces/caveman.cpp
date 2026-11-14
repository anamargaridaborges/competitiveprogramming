#include <bits/stdc++.h>

using namespace std;

int tam[300010], pai[300010];

int main () {
    int t;
    cin>>t;
    while (t--) {
        int n, m;
        cin>>n>>m;
        int save_m = m;
        for (int i=1; i<=n; i++) {
            tam[i] = 0, pai[i] = 0;
        }
        while (m--) {
            int a, b;
            cin>>a>>b;
            tam[a]++;
            tam[b]++;
            pai[a] = b;
            pai[b] = a;
        }
        if (n == 2 && save_m == 1) {
            cout<<"2"<<endl;
            continue;
        }
        bool eh_zero = false;
        for (int i=1; i<=n; i++) {
            if (tam[i] == 0) eh_zero = true;
        }
        if (eh_zero) {
            cout<<"Brain Melt"<<endl;
            continue;
        }
        int centro = -1;
        bool estrela = true;
        for (int i=1; i<=n; i++) {
            if (tam[i] > 1) {
                if (centro == -1) {
                    centro = i;
                }
                else {
                    estrela = false;
                }
            }
        }
        if (!estrela) {
            cout<<"Many"<<endl;
            continue;
        }
        for (int i=1; i<=n; i++) {
            if (tam[i] == 1) {
                if (pai[i] != centro) {
                    estrela = false;
                }
            }
        }
        cout<<(estrela ? "2" : "Many")<<endl;
    }
    return 0;
}