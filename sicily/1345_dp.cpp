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

#define MAXN  310
#define INF 0x5f3759df //for magic

//#define LOCAL
#define DEBUG
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
int f[MAXN][MAXN];
int num[MAXN];
int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
#endif
    int n;
    while(scanf("%d", &n) != EOF) {
        memset(f,0,sizeof(f));
        for (int i=1; i<=n; i++) {
            scanf("%d", &num[i]); num[i+n] = num[i];}
        for (int i=1; i<=2*n; i++)
        {
            debug("%d ", num[i]);
        }
        debug("\n");
        for (int step = 2; step <=n; step++) {
            for (int i=1; i<= 2*n; i++) {
                int j = i + step -1;
                //if (j > 2*n) break;
                for (int k=i; k <= j; k++) {
                    int temp = f[i][k] + f[k+1][j] + num[i] * num[k+1] * num[j+1];
                    if (i != j && f[i][j] < temp)
                        f[i][j] = temp;
                }}}
        int final = 0;
        for (int i=1; i<=n; i++) {
            if (f[i][i+n-1] > final) {
                final = f[i][i+n-1];
                debug("%d ", f[i][i+n-1]);
            }
        }
        cout<<final<<endl;

    }
}
