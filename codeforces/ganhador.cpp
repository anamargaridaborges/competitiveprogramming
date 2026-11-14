#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    cin>>n;
    int sets1 = 0, sets2 = 0;
    int pontos1 = 0, pontos2 = 0;
    int vencedor = 0;
    while (n--) {
        string s;
        cin>>s;
        if (s == "Kira") {
            pontos1++;
        }
        else {
            pontos2++;
        }
        if (pontos1 >= 4 && pontos1 - pontos2 >= 2) {
            sets1++;
            pontos1 = pontos2 = 0;
        }
        if (pontos2 >= 4 && pontos2 - pontos1 >= 2) {
            sets2++;
            pontos1 = pontos2 = 0;
        }
        if (sets1 == 2 && sets2 == 0) {
            vencedor = 1;
            break;
        }
        if (sets2 == 2 && sets1 == 0) {
            vencedor = 2;
            break;
        }
        if (sets1 == 3) {
            vencedor = 1;
            break;
        }
        if (sets2 == 3) {
            vencedor = 2;
            break;
        }
    }
    cout<<(vencedor == 1 ? "Kira" : "L")<<" eh melhor que "<<(vencedor == 1 ? "L" : "Kira")<<"!!!"<<endl;
}