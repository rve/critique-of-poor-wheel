#include <iostream>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 255;
int f[maxn][maxn],  s[maxn];
int main()
{
    int nn;
    while (cin>>nn) {
    memset(f,0, sizeof(f));
    for (int i=1; i<=nn; i++) {
        cin>>s[i];
    }
    for (int i=nn+1; i<=2*nn; i++) {
        s[i] = s[i-nn];
    }
    for (int len=1; len<=nn; len++) {
        for (int i=1; i<=2*nn; i++) {
            int j = i + len;
            if (j <= 2*nn)  {
                int mm = -1;
                for (int k=i; k<j; k++) {
                    mm = max(mm, f[i][k] + f[k+1][j] + s[i]*s[k+1]*s[j+1]);
                }
                f[i][j] = mm;
            }
        }
    }
    int best = -1;
    for (int i=1; i<=nn+1; i++) {
        best = max(best, f[i][i+nn-1]);
    }
    cout<<best<<endl;
    
}
}
