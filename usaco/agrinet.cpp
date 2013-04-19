/*
ID: jiongrr1
LANG: C++
TASK: agrinet
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 0x3f3f3f3f
#define MAXN 120
int m[MAXN][MAXN], dist[MAXN];
bool vis[MAXN];
int n, sum = 0;
int main()
{
    freopen("agrinet.in", "r", stdin);
    freopen("agrinet.out", "w", stdout);
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &m[i][j]);
    vis[0] = 1;
    for(int i=0; i<n; i++)
        dist[i] = m[0][i];

    for(int k=1; k<n; k++)
    {
        int mindist = INF;
        int minid;
        for(int i=0; i<n; i++)
        {
            if (!vis[i] && mindist > dist[i])
            {
                mindist = dist[i];
                minid = i;
            }       

        }
        vis[minid] = 1;
        sum += mindist;

        for(int i=0; i<n; i++)
            if (dist[i] > m[minid][i])
                dist[i] = m[minid][i];

    }
    printf("%d\n", sum);

}

