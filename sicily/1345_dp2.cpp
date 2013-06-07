#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int n, dp[100][101], a[210][3];

int main()
{

    while(scanf("%d",&n) != EOF)
    {
        int i, j, k;
        for(i = 0; i < n; i++)
        {
            scanf("%d",&a[i][0]);
            if(i > 0) a[i-1][1] = a[i][0];
        }
        a[n-1][1] = a[0][0];
        a[0][1] = a[1][0];

        for(i = 0; i < n; i++)
        {
            a[i+n][0] = a[i][0];
            a[i+n][1] = a[i][1];
        }

        for(k = 0; k < n; k++)
        {
            for(i = 0; i < 2 * n; i++)
            {
                for(j = i ; j < i + k; j++)
                {
				    int tmp = dp[i][j] + dp[j+1][i+k] + a[i][0] * a[j][1] * a[i+k][1];
				    if(tmp > dp[i][i+k]) dp[i][i+k] = tmp;
                }
            }
        }

        int ret = 0;
        for(i = 0; i < n; i++)
            ret = max(ret, dp[i][i+n-1]);
        printf("%d\n",ret);
    }
    return 0;
}
