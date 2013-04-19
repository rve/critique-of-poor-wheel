/*
ID:jiongrr1
LANG: C++
TASK: prefix
*/
#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
#include<stack>
#include<cstring>
#define MAXN 200001
using namespace std;
int main()
{
    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);
    int n = -1, v[MAXN], len = -1, sz[300];
    char p[300][20], s[MAXN], t[80];
    do
    {
        scanf("%s", p[++n]);
        sz[n] = strlen(p[n]);
    } while (p[n][0] != '.');
    while (scanf("%s", &t) != -1)
        strcat(s, t);

    int ndata = strlen(s), best = -1;
    v[0] = 1;
    for(int i = 0; i < ndata; i++)
        if (v[i])
        {
            best = i;
            for(int j = 0; j < n; j++)
                if (!v[i + sz[j]] && !strncmp(s + i, p[j], sz[j]))
                    v[i + sz[j]] = 1;
        }
    if (v[ndata]) best++;
    printf("%d\n", best);
}
