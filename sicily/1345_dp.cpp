#include<iostream>
#include<cstdio>
#include<cstring>
#define DEBUG
#ifdef DEBUG
#endif 
#define MAXN 302

#define INF 0x3f3f3f3f
using namespace std;
int f[MAXN][MAXN];
int main() {
    int n;
#ifdef DEBUG
    freopen("in")
    while (scanf("%d", &n) != EOF) {
        int d[MAXN];
        int i=0;
        scanf("%d", &d[i]);
        for (int i=1; i<2*n; i++) {
            scanf("%d", &d[i++]);
            d[i] = d[i-1];
        }
        d[2*n-1] = d[0];
        memset(f, 0, sizeof(f));
        int j;
        int temp = 0;
        for (int step=1; step<n; step++)
            for (int i=0; i<n*2; i++){
                j = i + step;
                if (j >= n*2 ) break;
                for (int k=i; k<j; k++) {
                    temp = f[i][k] + f[k+1][j] + d[i]*d[k+1]*d[j+1];
                    if (f[i][j] < temp)
                        f[i][j] = temp;
                }
            }
        cout<<f[0][2*n-1]<<endl;
    }
}
