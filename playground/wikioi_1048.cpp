#include <iostream>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 110;
int f[maxn][maxn],  s[maxn];
int sum[maxn];
int main()
{
    int nn;
    cin>>nn;
    memset(f,0, sizeof(f));
    memset(sum, 0, sizeof(sum));
    for (int i=1; i<=nn; i++) {
        cin>>s[i];
        sum[i] = sum[i-1] + s[i];
    }
    for (int len=1; len<=nn; len++) {
        for (int i=1; i<=nn; i++) {
            int j = i + len;
            if (j <= nn)  {
                int mm = INF;
                for (int k=i; k<j; k++) {
                    mm = min(mm, f[i][k]+f[k+1][j] + sum[j] - sum[i-1]);
                }
                f[i][j] = mm;
            }
        }
    }
    cout<<f[1][nn]<<endl;
}
