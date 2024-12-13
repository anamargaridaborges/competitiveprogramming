#include <bits/stdc++.h>
#define MAXS (int)2e5 + 10

using namespace std;

long long int dp[MAXS];
const int mod = (int)1e9 + 7;

long long int ex(long long int x, long long int n, long long int m) {
	x %= m;
	long long res = 1;
	while (n > 0) {
		if (n % 2 == 1) { 
            res = res*x%m; 
        }
		x = x*x%m;
		n /= 2;
	}
	return res;
}

int main () {
    int n;
    scanf ("%d", &n);
    int sum = ((n+1)*n)/2;
    if (sum%2 == 1) {
        // se a soma de 1 até n é ímpar, não conseguimos dividir em conjuntos de soma igual
        printf ("0\n");
        return 0;
    }
    sum = sum/2;
    // queremos saber de quantas formas 
    dp[0] = 1;
    long long int x = ex(2, mod-2, mod);
    for (int i=n; i>=1; i--) {
        for (int j=sum; j>=i; j--) {
            dp[j] += dp[j-i];
            dp[j] = dp[j]%mod;
        }
    }
    printf ("%lld\n", (dp[sum]*x)%mod);
    return 0;
}