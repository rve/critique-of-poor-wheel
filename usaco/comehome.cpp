/*
ID: jiongrr1
LANG: C++
TASK: comehome
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f
#define MAXN 160
int m[MAXN][MAXN];
int n;
int main()
{
    freopen("comehome.in", "r", stdin);
    freopen("comehome.out", "w", stdout);
    scanf("%d", &n);
    memset(m, INF, sizeof(m));
    for(int i=0; i<n; i++)
    {
        getchar();
        char a, b; int len;
        scanf("%c %c %d", &a, &b, &len);
        //printf("%c %c %d\n", a, b, len);
        if (m[a][b] > len)
        m[a][b] = m[b][a] = len;
    }
    for(int i=0; i<MAXN; i++)
        m[i][i] = 0;
    for(int k=0; k<MAXN; k++)
        for(int i=0; i<MAXN; i++)
            for(int j=0; j<MAXN; j++)
                if (m[i][k] + m[k][j] < m[i][j])
                    m[i][j] = m[i][k] + m[k][j];
    int ans = INF;
    int ansn;
    for(int i = 'A'; i < 'Z'; i++)
        if(m[i]['Z'] < ans)
        {
            ans = m[i]['Z'];
            ansn = i;
        }
    printf("%c %d\n", ansn, ans);
            


}
