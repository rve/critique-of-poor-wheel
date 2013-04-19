/*
ID: jiongrr1
LANG: C++
TASK: inflate
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 0x3f3f3f3f
#define MAXN 10010
using namespace std;
int problems[MAXN][2];
int F[MAXN];
int main()
{
    freopen("inflate.in", "r", stdin);
    freopen("inflate.out", "w", stdout);
    int m, n;
    scanf("%d %d", &m, &n);
    memset(problems, 0, sizeof(problems));
    memset(F, 0, sizeof(F));
    for(int i=0; i<n; i++)
    {
        int minutes, score;
        scanf("%d %d", &score, &minutes);
        problems[i][0] = minutes;
        problems[i][1] = score;
    }
    for(int i=0; i<n; i++)
        for(int j = problems[i][0]; j <= m; j++)
        {
            F[j] = max(F[j], F[j - problems[i][0]] + problems[i][1]);
        }

    printf("%d\n", F[m]);
}

