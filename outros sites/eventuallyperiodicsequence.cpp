#include <bits/stdc++.h>
#define lli long long int

using namespace std;

lli calc (string s, lli atual, lli N) {
    stack<lli> aux;
    lli num_atual = 0;
    for (int j=1; j<(int)s.size(); j++) {
        if (num_atual != 0 && (s[j]<48 || s[j]>57)) {
            aux.push(num_atual);
            num_atual = 0;
        }
        if (s[j]=='x') aux.push(atual);
        else if (s[j]=='N') aux.push(N);
        else if (s[j]>=48 && s[j]<=57) {
            num_atual *= 10;
            num_atual += s[j]-'0';
        }
        else if (s[j]=='+') {
            lli x = aux.top();
            aux.pop();
            lli y = aux.top();
            aux.pop();
            aux.push((x+y)%N);
        }
        else if (s[j]=='*') {
            lli x = aux.top();
            aux.pop();
            lli y = aux.top();
            aux.pop();
            aux.push((x*y)%N);
        }
        else if (s[j]=='%') {
            lli x = aux.top();
            aux.pop();
            lli y = aux.top();
            aux.pop();
            aux.push(y%x);
        }
    }
    lli resp = aux.top();
    aux.pop();
    return resp;
}

int main () {
    while (true) {
        ios_base::sync_with_stdio(0); cin.tie(0);
        lli N, n;
        cin>>N>>n;
        string comando;
        getline(cin, comando);
        if (N==0) break;
        map<lli, int> ciclo;
        lli atual = n;
        for (int i=1; ; i++) {
            if (ciclo.find(atual) != ciclo.end()) {
                cout<<i-ciclo[atual]<<endl;
                break;
            }
            ciclo[atual] = i;
            atual = calc(comando, atual, N);
        }
        ciclo.clear();
    }
    return 0;
}