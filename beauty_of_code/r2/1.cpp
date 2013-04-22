#include<iostream>
#include<string>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cstdio>
#define MAXN 52 
#define INF 0x5f3759df //for magic
using namespace std;
const double  PI = acos(-1.0); //M_PI;
struct pp
{
    int q1,c1,q2,c2;
};

int main()
{
    pp f[502][502]; // 1 2 3 4 = Q1 C1 Q2 C2
    int T;
    scanf("%d", &T);
    for (int o=1; o<=T; o++)
    {
        int n, n1, n2;
        scanf("%d %d %d", &n, &n1, &n2);
        memset(f, 0, sizeof(f));
        int fa[502][4];
        pp tmp[502];
        for (int i=1; i<=n; i++)
            scanf("%d %d %d %d", &fa[i][1], &fa[i][2], &fa[i][3], &fa[i][4]);
        for (int i=1; i<=n; i++)
        {
            tmp[i].q1 = fa[i][1];
            tmp[i].c1 = fa[i][2];
            tmp[i].q2 = fa[i][3];
            tmp[i].c2 = fa[i][4];
        }
        for (int i=1; i<=n1; i++)
        {
            for (int j=1; j<=n2; j++)
            {



            }
        }


    }
}
