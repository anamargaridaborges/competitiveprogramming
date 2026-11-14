#include <bits/stdc++.h>

using namespace std;

int main () {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        vector<int> impar, par;
        for (int i=1; i<=n; i++) {
            int x;
            cin>>x;
            if (i%2 == 1) impar.push_back(x);
            else par.push_back(x);
        }
        if (n == 1) {
            cout<<"YES"<<endl;
            continue;
        }
        sort(impar.begin(), impar.end());
        sort(par.begin(), par.end());
        int idx_p = 0;
        int tam_p = (int)par.size();
        int ultimo = -1;
        vector<int> resto_impar, resto_par;
        bool ultimo_impar = false;
        for (int i=0; i<(int)impar.size(); i++) {
            if (ultimo > impar[i]) {
                resto_impar.push_back(impar[i]);
            }
            else {
                // coloco esse impar e seleciono um par também
                ultimo = impar[i];
                //cout<<ultimo<<" ";
                ultimo_impar = true;
                while (idx_p < tam_p && par[idx_p] < ultimo) {
                    resto_par.push_back(par[idx_p]);
                    idx_p++;
                }
                if (idx_p == tam_p) {
                    for (int j=i+1; j<(int)impar.size(); j++) {
                        resto_impar.push_back(impar[j]);
                    }
                    break;
                }
                ultimo = par[idx_p];
                idx_p++;
                ultimo_impar = false;
                //cout<<ultimo<<" ";
            }
        }
        while (idx_p < tam_p) {
            resto_par.push_back(par[idx_p]);
            idx_p++;
        }
        reverse(resto_impar.begin(), resto_impar.end());
        reverse(resto_par.begin(), resto_par.end());
        bool check = true;
        if (!ultimo_impar) {
            idx_p = 0;
            int tam_resto_p = (int)resto_par.size();
            for (int i=0; i<(int)resto_impar.size(); i++) {
                if (ultimo < resto_impar[i]) {
                    check = false;
                    break;
                }
                else {
                    // coloco esse impar e preciso colocar o proximo par
                    ultimo = resto_impar[i];
                    //cout<<ultimo<<" ";
                    if (idx_p == tam_resto_p) continue;
                    if (resto_par[idx_p] > ultimo) {
                        check = false;
                        break;
                    }
                    ultimo = resto_par[idx_p];
                    //cout<<ultimo<<" ";
                    idx_p++;
                }
            }
            //cout<<endl;
        }
        else {
            int idx_i = 0;
            int tam_resto_i = (int)resto_impar.size();
            for (int i=0; i<(int)resto_par.size(); i++) {
                if (ultimo < resto_par[i]) {
                    check = false;
                    break;
                }
                else {
                    // coloco esse par e preciso colocar o proximo impar
                    ultimo = resto_par[i];
                    //cout<<ultimo<<" ";
                    if (idx_i == tam_resto_i) continue;
                    if (resto_impar[idx_i] > ultimo) {
                        check = false;
                        break;
                    }
                    ultimo = resto_impar[idx_i];
                    //cout<<ultimo<<" ";
                    idx_i++;
                }
            }
        }
        if (check) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}