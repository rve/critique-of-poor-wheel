/*
ID: jiongrr1
LANG: C++
TASK: cowtour
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 0x3f3f3f3f
#define MAXN 160
double m[MAXN][MAXN], len[MAXN][MAXN];
int n;
double x[MAXN], y[MAXN];
double largest[MAXN];
inline double dist(int i, int j)
{
    return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}
int main()
{
    freopen("cowtour.in", "r", stdin);
    freopen("cowtour.out", "w", stdout);

    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        int xx, yy;
        scanf("%d %d", &xx, &yy);
        y[i] = xx; x[i] = yy;
    }
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            len[i][j] = dist(i, j);

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            m[i][j] = 1e20;
    for(int i=0; i<n; i++)
    {
        getchar();
        for(int j=0; j<n; j++)
        {
            char c;
            scanf("%c", &c);
            if (c == '1')
            {
                m[i][j] = len[i][j];
            }
        }
    }       
    for(int i=0; i<n; i++)
        m[i][i] = 0;


    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if (m[i][k] + m[k][j] < m[i][j])
                    m[i][j] = m[i][k] + m[k][j];



    memset(largest, 0, sizeof(largest));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            if (m[i][j] != 1e20 && m[i][j] > largest[i])
                largest[i] = m[i][j];
    }

    double ans = 1e20;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            if (m[i][j] == 1e20)
            {
                if (largest[i] + largest[j] + len[i][j] < ans)
                    ans = largest[i] + largest[j] + len[i][j];
            }

        }

    for(int i=0; i<n; i++)
        if (largest[i] != 1e20 && largest[i] > ans)
            ans = largest[i];

    printf("%.6lf\n", ans);
}
