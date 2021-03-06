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

#define MAXN 40010
#define INF 0x5f3759df //for magic

//#define LOCAL
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
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        int a[MAXN];
        scanf("%d", &n);
        for (int i=1; i<=n; i++)
            scanf("%d", &a[i]);
        int nn = 0; int c[MAXN], b[MAXN];
        c[0] = 0;
        for (int i=1; i<=n; i++) {
            if(a[i] > c[nn]) {
                c[++nn] = a[i];
                b[i] = nn;
            }
            else {
                int hi = upper_bound(c, c+nn+1, a[i]) - c;
                c[hi] = a[i];
                b[i] = hi;}}
    printf("%d\n", nn);
    }
}
