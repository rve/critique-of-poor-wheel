#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 10010
#define INF ((int)1e10)
using namespace std;
int main()
{
    int n;
    int m[12][12];
    int dp[(1<<12)+1][12];
    while(scanf("%d", &n) , n != 0)
    {
        memset(dp, 0, sizeof(dp));
        memset(m, 0, sizeof(m));
        n++;
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
            {
                scanf("%d", &m[i][j]);
//                if (m[i][j] == 0) m[i][j] = INF;
            }
 //       for (int i=0; i<n; i++) m[i][i] = 0;
        for (int k=0; k<n; k++)
            for (int i=0; i<n; i++)
                for (int j=0; j<n; j++) {
                    if (m[i][k] + m[k][j] < m[i][j]) {
                        m[i][j] = m[i][k] + m[k][j];}
                }
        //dp
        for (int S = 0; S <= (1<<(n-1)) -1; S++) {
            for (int i=1; i <n; i++)
            if ( S & (1 << (i -1))) 
            {
                if (S == (1<<(i-1))) {
                    dp[S][i] = m[0][i];
                }
                else {
                    dp[S][i] = INF;
                    for (int j=1; j<n; j++)
                        if (S & (1<<(j -1)) && j != i)
                            dp[S][i] = min (dp[S][i], dp[S ^ (1<<(i-1))][j] + m[j][i]);
                }
            }
        }
        int best  = dp[(1<<(n-1)) -1][1] + m[1][0];
        for (int i=2; i<n; i++)
            if (dp[(1<<(n-1) -1)][i] + m[i][0]  < best)
                best = dp[(1<<(n-1)) -1][i] + m[i][0];
        printf("%d\n", best);
    }
}
