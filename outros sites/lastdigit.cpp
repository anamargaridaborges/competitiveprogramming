#include <bits/stdc++.h>

using namespace std;

long long int soma[110];
long long int soma_parcial[110];

long long int exp (int x, int y) {
    long long int ans = x;
    for (int j=2; j<=y; j++) {
        ans = (ans*x)%10;
    }
    return ans;
}

int main () {
    soma[1]=1;
    soma_parcial[1]=1;
    for (int i=2; i<=100; i++) {
        soma[i] = exp(i, i);
        soma[i] += soma[i-1];
        soma[i] = soma[i]%10;
        soma_parcial[i] = (soma[i]+soma_parcial[i])%10;
    }
    while (true) {
        string s;
        cin>>s;
        if (s[0]=='0') break;
        long long int ans = 0;
        for (int i=0; i<(int)s.size()-2; i++) {
            if (s[i]=='0') continue;
            ans += soma[100];
            ans = ans%10;
        }
        int help;
        if ((int)s.size()==1) help = (s[(int)s.size()-1]-'0');
        else help = (s[(int)s.size()-2]-'0')*10 + (s[(int)s.size()-1]-'0');
        ans += soma_parcial[help];
        ans = ans%10;
        cout<<ans<<endl;
    }
    return 0;
}