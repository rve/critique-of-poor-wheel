#include<cstring>
#include<cstdio>
#include<cstring>
using namespace std;
char a[200];
int f[110][110][110];
int maxi[110]; 
int maxLastLen[110][110][110];
int maxNowLen[110][110];
char ans[110][110];

bool isOk(int i , int l , int j , int k)
{
    int s1 = i - l;
    int s2 = j - k;
    while (s1 < i && s2 < j && a[s1] == a[s2])
    {
        s1++;
        s2++;
    }
    if (s1 == i && s2 == j) return false;
    if (s1 == i) return false;
    if (s2 == j) return true;
    if (a[s1] < a[s2]) return false;
    if (a[s1] > a[s2]) return true;
}

void dfs(int i,int k,int len)
{
    if (k == 0) return;
    dfs(i - len,k-1,maxLastLen[i][k][len]);
    int l = 0;
    for (int j = i - len; j < i ; j++)
        ans[k][l++] = a[j];
    ans[k][l] = '\0';
}

int main()
{
    while (true)
    {
        scanf("%s",a);
        int n = strlen(a);
        if (n == 1) break;
        memset(f,0,sizeof(f));
        memset(maxi,0,sizeof(maxi));
        memset(maxLastLen,0,sizeof(maxLastLen));
        memset(maxNowLen,0,sizeof(maxNowLen));
        f[2][1][2] = 1;
        f[0][0][0] = 1;
        maxi[2] = 1;
        maxNowLen[2][1] = 2;
        for (int i = 3 ; i <= n ; i++)
            for (int j = 1 ; j <= i/2 ; j++)
                for (int l = 2 ; l <= i ; l++)
                {
                    for (int k = 0 ; k <= i - l ; k++)
                        if (f[i-l][j-1][k])
                        {
                            if (isOk(i,l,i-l,k))
                            {
                                f[i][j][l]+=f[i-l][j-1][k];
                                if (j > maxi[i]) maxi[i] = j;
                                if (l > maxNowLen[i][j])
                                    maxNowLen[i][j] = l;
                                if (k > maxLastLen[i][j][l])
                                    maxLastLen[i][j][l] = k;
                            }
                        }
                }
        int total = 0;
        for (int i = 2 ; i <= n ; i++)
            if (f[n][maxi[n]][i]) total += f[n][maxi[n]][i];
        printf("%d %d\n",maxi[n],total);
        dfs(n,maxi[n],maxNowLen[n][maxi[n]]);
        printf("%s",ans[1]);
        for (int i = 2 ; i <= maxi[n] ; i++)
            printf(" %s",ans[i]);
        printf("\n");
    }
    return 0;
}
