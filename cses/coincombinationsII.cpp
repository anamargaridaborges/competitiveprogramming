#include <bits/stdc++.h>
#define MAXN (int)1e6 + 10
#define MAXS 110
 
using namespace std;
 
int dp[MAXN];
 
int main()
{
	
	int n, x;
	scanf ("%d%d", &n, &x);
	
	int vet[MAXS];
	for (int i=1; i<=n; i++) scanf ("%d", &vet[i]);
	
	dp[0]=1;
	
	for (int i=n; i>=1; i--) {
		for (int j=vet[i]; j<=x; j++) {
			dp[j]+=dp[j-vet[i]];
			dp[j]=dp[j]%1000000007;
		}
	}
	printf ("%d", dp[x]);
	return 0;
}