#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdio>
#define MAXN 10010
#define INF 0x3f3f3f3f
using namespace std;
    int 
gcd ( int a, int b )
{
    int c;
    while ( a != 0 ) {
        c = a; a = b%a;  b = c;
    }
    return b;
}
int main()
{
    int n, m;
    int d[MAXN][31];
    while(scanf("%d %d", &n, &m), n != 0 && m != 0)
    {
        for(int j=0; j<n; j++)
            for(int i=0; i<m; i++)
            {
                scanf("%d", &d[j][i]);
            }
        int sum = 0;
        for(int i=0; i<n; i++)
            sum += d[i][m-1];
        for(int i=0; i<n; i++)
        {
            int g = gcd(d[i][m-1], sum);
            if (d[i][m-1] != 0)
                printf("%d / %d\n", d[i][m-1] / g, sum / g);
            else
                printf("0 / 1\n");
        }
    }
}
