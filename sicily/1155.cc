#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
 
const int MAXM = 50000;
const int MAXN = 250;
const int EXP = 10;
 
const int INF = 0x3f3f3f3f;
int main(){
    int m[MAXN][MAXN];
    int n, d;
    while(scanf("%d%d", &n, &d) , n != 0){
        memset(m, 0x3f, sizeof(m));
        int f,t;
        for (int i=0; i<d; i++) {
        scanf("%d%d", &f, &t);
        m[f][t] = 1;
        }
    for (int i=0; i<n; i++){
            m[i][i] = 0;
    }
    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++){
                if (m[i][j] > m[i][k] + m[k][j]) {
                    m[i][j] = m[i][k] + m[k][j];
                }
            }
        }
    }
    if (m[0][n-1] < INF) cout<<m[0][n-1]<<endl;
    if (m[0][n-1] < INF) cout<<"I can post the letter"<<endl;
    else cout<<"I can't post the letter"<<endl;
    }
}
