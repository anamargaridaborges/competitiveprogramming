#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;

int z1[MAXN], z2[MAXN];

const long long int mod = 1e18 + 3;
const int primo = 37;

long long int pot1[MAXN];

int main () {
    pot1[0] = 1;
    for (int i=1; i<MAXN; i++) {
        pot1[i] = (pot1[i-1]*primo)%mod;
    }
    char s1[MAXN], s2[MAXN];
    scanf ("%s%s", s1, s2);
    int n = strlen(s1);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z1[i] = min(r - i, z1[i - l]);
        }
        while(i + z1[i] < n && s1[z1[i]] == s1[i + z1[i]]) {
            z1[i]++;
        }
        if(i + z1[i] > r) {
            l = i;
            r = i + z1[i];
        }
    }
    n = strlen(s2);
    l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z2[i] = min(r - i, z2[i - l]);
        }
        while(i + z2[i] < n && s2[z2[i]] == s2[i + z2[i]]) {
            z2[i]++;
        }
        if(i + z2[i] > r) {
            l = i;
            r = i + z2[i];
        }
    }
    long long int pref1 = 0;
    int tam1 = strlen(s1), tam2 = strlen(s2);
    vector<long long int> div1, div2;
    for (int i=0; i<tam1; i++) {
        pref1 = (pref1 + (s1[i]-96)*pot1[i])%mod;
        if ((i+1)+z1[i+1] == tam1 && tam1%(i+1)==0) {
            div1.push_back(pref1);
        }
    }
    pref1 = 0;
    for (int i=0; i<tam2; i++) {
        pref1 = (pref1 + (s2[i]-96)*pot1[i])%mod;
        if ((i+1)+z2[i+1] == tam2 && tam2%(i+1)==0) {
            div2.push_back(pref1);
        }
    }
    sort(div1.begin(), div1.end());
    sort(div2.begin(), div2.end());
    int ans = 0;
    for (int i=0; i<(int)div1.size(); i++) {
        int l = 0, r = (int)div2.size()-1, mid;
        while (l<=r) {
            mid = (l+r)/2;
            if (div2[mid] == div1[i]) {
                ans++;
                break;
            }
            if (div2[mid]<div1[i]) l = mid+1;
            if (div2[mid]>div1[i]) r = mid-1;
        }
    }
    printf ("%d\n", ans);
    return 0;
}