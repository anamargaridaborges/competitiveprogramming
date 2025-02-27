#include <bits/stdc++.h>

using namespace std;

typedef struct t_vetor {
    long long int x, y;
    long long int cross (t_vetor q) {
        return x*q.y-y*q.x;
    }
}t_vetor;

int main () {
    int n;
    scanf ("%d", &n);
    t_vetor vet[1010];
    for (int i=1; i<=n; i++) scanf ("%lld%lld", &vet[i].x, &vet[i].y);
    long long int ans = 0;
    for (int i=1; i<n; i++) ans += vet[i].cross(vet[i+1]);
    ans += vet[n].cross(vet[1]);
    printf ("%lld\n", abs(ans));
    return 0;
}