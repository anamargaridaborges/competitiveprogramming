#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> primos;
int eh_primo[10010];
int ans;

void crivo() {
    for (int i=2; i<=10000; i++) {
        if (eh_primo[i]) continue;
        for (int j=2*i; j<=10000; j+=i) eh_primo[j] = 1;
        primos.push_back(i);
    }
}

int mul(int a, int b, int m) {
	int ret = a*b - (int)((long double)1/m*a*b+0.5)*m;
	return ret < 0 ? ret+m : ret;
}

int pow(int x, int y, int m) {
	if (!y) return 1;
	int ans = pow(mul(x, x, m), y/2, m);
	return y%2 ? mul(x, ans, m) : ans;
}

bool prime(int n) {
	if (n < 2) return 0;
	if (n <= 3) return 1;
	if (n % 2 == 0) return 0;
	int r = __builtin_ctzll(n - 1), d = n >> r;

 	// com esses primos, o teste funciona garantido para n <= 2^64
	// funciona para n <= 3*10^24 com os primos ate 41
	for (int a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
		int x = pow(a, d, n);
		if (x == 1 or x == n - 1 or a % n == 0) continue;
		
		for (int j = 0; j < r - 1; j++) {
			x = mul(x, x, n);
			if (x == n - 1) break;
		}
		if (x != n - 1) return 0;
	}
	return 1;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    crivo();
    int t;
    cin>>t;
    for (int i=1; i<=t; i++) {
        int a, b;
        cin>>a>>b;
        int aux = a;
        ans = 0;
        int divisores = 1;
        if (b * b >= a) {
            cout<<"Case "<<i<<": "<<0<<"\n";
            continue;
        }
        for (int p : primos) {
            if (p*p*p > a) break;
            int pot = 1;
            while (a%p == 0) {
                a = a/p;
                pot++;
            }
            divisores *= pot;
        }
        if (prime(a)) divisores*=2;
        else if (prime(sqrt(a)) && (int)sqrt(a) == (double)sqrt(a)) divisores*=3;
        else if (a != 1) divisores*=4;
        divisores = divisores/2;
        for (int i=1; i<b; i++) {
            if (aux % i == 0 && aux/i < b) break;
            if (aux % i == 0) divisores--;
        }
        cout<<"Case "<<i<<": "<<divisores<<"\n";
    }
    return 0;
}