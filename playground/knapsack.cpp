#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 30050
using namespace std;
int main() {
    freopen("data.in", "r", stdin);
    int n,m;
    while (cin>>m>>n) {
    int k[10009];
    int p[10009];
    int f[30050];
    memset(f, 0, sizeof(f));
    int mmin = 0x3f3f3f3f;
    for (int i=1; i<=n; i++) {
        scanf("%d%d", &k[i], &p[i]);
        mmin = min(k[i], mmin);
    }
    for (int i=1; i<=n; i++) {
        for (int j=m; j>=mmin; j--) {
            if (j - k[i] >= 0) {
                f[j] = max(f[j], f[j-k[i]] + p[i] * k[i]);
            }
        }
    }
    printf("%d\n", f[m]);
    
}}
