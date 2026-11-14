#include <bits/stdc++.h>

using namespace std;

int tam_ini = 0;
int tam_fim = 0;
vector<int> insercoes_ini, insercoes_fim;
vector<int> tempos_ini[100010], tempos_fim[100010];
int t;
int n, m, q;
int tam_pais_ini[100010], tam_pais_fim[100010];

void inserir_ini(int p) {
    t++;
    tempos_ini[p].push_back(t);
    insercoes_ini.push_back(t);
    tam_ini++;
    tam_pais_ini[p]++;
}

void inserir_fim(int p) {
    t++;
    tempos_fim[p].push_back(t);
    insercoes_fim.push_back(t);
    tam_fim++;
    tam_pais_fim[p]++;
}

int quantos_ini_maiores_iguais (int x) {
    int l_ins = 0, r_ins = tam_ini - 1, mid_ins;
    int ans_ins = -1;
    while (l_ins <= r_ins) {
        mid_ins = (l_ins+r_ins)/2;
        if (insercoes_ini[mid_ins] >= x) {
            ans_ins = mid_ins;
            r_ins = mid_ins - 1;
        }
        else l_ins = mid_ins + 1;
    }
    return tam_ini-ans_ins;
}

int quantos_fim_menores_iguais (int x) {
    int l_ins = 0, r_ins = tam_fim - 1, mid_ins;
    int ans_ins = -1;
    while (l_ins <= r_ins) {
        mid_ins = (l_ins+r_ins)/2;
        if (insercoes_fim[mid_ins] <= x) {
            ans_ins = mid_ins;
            l_ins = mid_ins + 1;
        }
        else r_ins = mid_ins - 1;
    }
    return ans_ins+1;
}

void print_pos_ini (int p) {
    cout<<p<<endl;
    for (int i=0; i<tam_pais_ini[p]; i++) {
        cout<<quantos_ini_maiores_iguais(tempos_ini[p][i])<<" ";
    }
    cout<<endl;
}

void print_pos_fim (int p) {
    cout<<p<<endl;
    for (int i=0; i<tam_pais_fim[p]; i++) {
        cout<<tam_ini+quantos_fim_menores_iguais(tempos_fim[p][i])<<" ";
    }
    cout<<endl;
}

int query(int l0, int r0, int p) {
    // pros caras inseridos no começo, calculo quantos tem no intervalo
    int l = 0, r = tam_pais_ini[p]-1, mid;
    int ans = -1;
    //print_pos_ini(p);
    //print_pos_fim(p);
    // a lista ini é invertida
    while (l <= r) {
        mid = (l+r)/2;
        int pos = quantos_ini_maiores_iguais(tempos_ini[p][mid]);
        if (pos >= l0) {
            // procuro pos menor que ainda é maior igual a l0
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    // ans é o primeiro cara com posicao maior igual a l0
    int primeiro_cara = ans;
    l = 0, r = tam_pais_ini[p]-1, ans = -1;
    // calculo qual o último índice menor ou igual a r0
    while (l <= r) {
        mid = (l+r)/2;
        int pos = quantos_ini_maiores_iguais(tempos_ini[p][mid]);
        if (pos <= r0) {
            // procuro pos maior que ainda é menor igual a r0
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    int ultimo_cara = ans;
    int resp;
    if (primeiro_cara == -1 || ultimo_cara == -1) {
        resp = 0;
    }
    else resp = -ultimo_cara + primeiro_cara + 1;
    // faço a conta agora pros caras inseridos no final
    // a posicao deles é todos os caras inseridos no inicio + os caras do fim inseridos antes dele
    l = 0, r = tam_pais_fim[p]-1, ans = -1;
    while (l <= r) {
        mid = (l+r)/2;
        int pos = tam_ini + quantos_fim_menores_iguais(tempos_fim[p][mid]);
        if (pos >= l0) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    primeiro_cara = ans;
    l = 0, r = tam_pais_fim[p]-1, ans = -1;
    while (l <= r) {
        mid = (l+r)/2;
        int pos = tam_ini + quantos_fim_menores_iguais(tempos_fim[p][mid]);
        if (pos <= r0) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    ultimo_cara = ans;
    if (primeiro_cara == -1 || ultimo_cara == -1) {
        return resp;
    }

    return resp + (ultimo_cara - primeiro_cara + 1);
}

int main () {
    int n, m, q;
    cin>>n>>m>>q;
    for (int i=1; i<=n; i++) {
        int x;
        cin>>x;
        inserir_fim(x);
    }
    while (q--) {
        int op;
        cin>>op;
        if (op == 1) {
            int d, x;
            cin>>d>>x;
            if (d == -1) inserir_ini(x);
            else inserir_fim(x);
        }
        else {
            int l, r, x;
            cin>>l>>r>>x;
            cout<<query(l, r, x)<<endl;
        }
    }
}