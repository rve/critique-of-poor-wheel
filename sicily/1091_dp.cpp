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

#define MAXN 50010
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
    int  T = 0;
    scanf("%d", &T);
    while (T--) {
      int n;
      scanf("%d", &n);
        int a[MAXN];
      for (int i=0; i<n; i++) scanf("%d", &a[i]);
      int s1[MAXN], s2[MAXN];
      memset(s1, 0, sizeof(s1));
      memset(s2, 0, sizeof(s2));
      int sum=0, ans = 0;
      ans = -1 * INF;
      for (int i=0; i<n; i++) {
        sum += a[i];
        if (sum > ans) ans = sum;
        s1[i] = ans;
        if (sum < 0) sum =0;
      }
      sum = ans = 0;
      ans = -1 *INF;
      for (int i=n-1; i>=0; i--) {
        sum += a[i];
        if (sum > ans) ans = sum;
        s2[i] = ans;
        if (sum < 0) sum =0;
      }
      sum = ans = 0;
      ans = -1 *INF;
      for (int i=1; i<n; i++) {
        if (s1[i-1] + s2[i] > ans) ans = s1[i-1] + s2[i];
      }
      cout<<ans<<endl;
    }
}
