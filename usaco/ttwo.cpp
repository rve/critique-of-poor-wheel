/*
ID: jiongrr1
LANG: C++
TASK: ttwo
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 1010
using namespace std;
bool valid(int, int);
int m[MAXN][MAXN];
int dc = 0, dj = 0;
int d[4][2] = {{-1, 0}, {0,1}, {1,0}, {0, -1}};
bool meet = 0;
int main()
{
    freopen("ttwo.in", "r", stdin);
    freopen("ttwo.out", "w", stdout);
    int xc, yc, xj, yj;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            scanf("%c", &m[i][j]);
            if (m[i][j] == 'C')
            {
                m[i][j] = '.';
                xc = i; yc = j;
            }
            else if (m[i][j] == 'F')
            {
                m[i][j] = '.';
                xj = i; yj = j;
            }
        }
        getchar();
    }

    int i;
    for(i = 0; i < MAXN; i++)
    {
        int xxc = xc + d[dc][0];
        int yyc = yc + d[dc][1];
        int xxj = xj + d[dj][0];
        int yyj = yj + d[dj][1];
        if (valid(xxc, yyc))
        {
            xc = xxc; yc = yyc;
        }
        else
        {
            dc = (dc + 1) % 4;
            //xc += d[dc][0]; yc += d[dc][1];
        }
        if (valid(xxj, yyj))
        {
            xj = xxj; yj = yyj;
        }
        else
        {
            dj = (dj + 1) % 4;
            //xj += d[dj][0]; yj += d[dj][1];
        }

        //printf("Cow @ (%d, %d) John @ (%d, %d)\n", xc, yc, xj, yj);//debug
        if (xc == xj && yc == yj)
        {
            meet = 1; break;
        }
    }

    if (meet)
        printf("%d\n", i+1);
    else
        printf("0\n");
}
inline bool valid(int x, int y)
{
    if (x >= 0 && y >= 0 && x < 10 && y < 10)
        if ( m[x][y] != '*')
            return true;

    return false;
}
