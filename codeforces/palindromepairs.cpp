#include <bits/stdc++.h>

using namespace std;

map<long long int, int> m;
long long int pot[30];
int freq[30];

int main () {
    int n;
    cin>>n;
    pot[0]=1;
    for (int i=1; i<=26; i++) pot[i] = pot[i-1]*2;
    long long int ans = 0;
    for (int i=1; i<=n; i++) {
        string s;
        cin>>s;
        for (int j=0; j<30; j++) freq[j]=0;
        for (int j=0; j<(int)s.size(); j++) freq[s[j]-97]++;
        long long int bitm = 0;
        for (int j=0; j<26; j++) bitm += (freq[j]%2)*pot[j];
        ans += m[bitm];
        for (int j=0; j<26; j++) {
            ans += m[bitm^pot[j]];
        }
        m[bitm]++;
    }
    cout<<ans<<endl;
    return 0;
}