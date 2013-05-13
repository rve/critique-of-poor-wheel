#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAXM = 50000;
const int MAXN = 250;
const int EXP = 10;

const int INF = 0x3f3f3f3f;
struct point {
    int x, y;
}
int main(){
    int m[MAXN][MAXN];
    int nn, d, n;
    scanf("%d", &nn);
    while(nn--){
        scanf("%d%d", &n, &d);
        memset(m, 0, sizeof(m));
        int f,t;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=d; j++) {
                scanf("%d", &f);
                m[i][j] = f;
            }
        }

        point s, t;
        cin>>s.x>>s.y>>t.x>>t.y;
        for (int i=0; i<n; i++){
            m[i][i] = 1;
        }
        queue<int> q;
        q.push()
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
        if (m[0][n-1] < INF) cout<<1<<endl;
        else cout<<0<<endl;
    }
}
