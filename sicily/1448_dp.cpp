#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <climits>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>

#define MAXN 300
#define INF 0x5f3759df //for magic

#define LOCAL
//#define DEBUG
#ifdef DEBUG
#define debug(...) printf( __VA_ARGS__) 
#else
#define debug(...)
#endif

using namespace std;
const int MOD = int(1e9) + 7;
const double  PI = acos(-1.0); //M_PI;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

template<class T> inline T min(T a, T b, T c){return min(min(a, b), c);}
template<class T> inline T max(T a, T b, T c){return max(max(a, b), c);}
template<class T> inline T min(T a, T b, T c, T d){return min(min(a, b), min(c, d));}
template<class T> inline T max(T a, T b, T c, T d){return max(max(a, b), max(c, d));}
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline T cub(T a){return a*a*a;}

int main()
{
#ifdef LOCAL 
    freopen("data.in","r",stdin);  
#endif
    int a[MAXN];
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        for (int i=1; i<=n; i++)
            scanf("%d", &a[i]);


        int f[MAXN][MAXN];
        f[0][0] = 0;
        //    memset(f, 1, sizeof(f));
        for (int i=1; i<=n; i++)
            f[i][i] = 1;

        for (int i=1; i<=n;i++) {
            for (int j=i+1; j<=n; j++)
            {
                if ( j & 1) {
                    if (f[i][j-1] == 2 && a[j] > a[j-1]) f[i][j] = f[i][j-1] + 1;
                    else f[i][j] = 1;
                }
                else
                {
                    if (a[j] < a[j-1]) f[i][j] = f[i][j-1] + 1;
                    else f[i][j] = 1;
                }
            }
        }
        int final = 0;
        for (int i=1; i<=n; i++)
        {
            for (int j= 1; j<=n; j++)
                if (f[i][j] > final)
                    final = f[i][j];
        }
        cout<<final<<endl;
    }
}
