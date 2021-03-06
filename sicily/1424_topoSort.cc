//#define LOCAL
#define DEBUG

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#if __cplusplus > 201103L
#include <initializer_list>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;
#define INF 0x3f3f3f3f
#ifdef DEBUG
#define cvar(x) cerr << "<" << #x << ": " << x << ">"
#define evar(x) cvar (x) << endl
#define debug(...) printf( __VA_ARGS__)
template<class T> void DISP(const char *s, T x, int n) {cerr << "[" << s << ": "; for (int i = 0; i < n; ++i) cerr << x[i] << " "; cerr << "]" << endl;}
#define disp(x,n) DISP(#x " to " #n, x, n)
#else
#define debug(...)
#define cvar(...) ({})
#define evar(...) ({})
#define disp(...) ({})
#endif
#define car first
#define cdr second
#define PB push_back
#define SZ(x) (int)((x).size())
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (int _end_ = (b), i = (a); i <= _end_; ++i)
#define ROF(i, a, b) for (int _end_ = (b), i = (a); i >= _end_; --i)

typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;
typedef long double real;

int64 fpm(int64 b, int64 e, int64 m) { int64 t = 1; for (; e; e >>= 1, b = b * b % m) e & 1 ? t = t * b % m : 0; return t; }
template<class T> inline bool chkmin(T &a, T b) {return a > b ? a = b, true : false;}
template<class T> inline bool chkmax(T &a, T b) {return a < b ? a = b, true : false;}
template<class T> inline T min(T a, T b, T c){return min(min(a, b), c);}
template<class T> inline T max(T a, T b, T c){return max(max(a, b), c);}
template<class T> inline T min(T a, T b, T c, T d){return min(min(a, b), min(c, d));}
template<class T> inline T max(T a, T b, T c, T d){return max(max(a, b), max(c, d));}
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline T cub(T a){return a*a*a;}
template <typename T> T gcd(T x, T y) {for (T t; x; t = x, x = y % x, y = t); return y; }



const int maxn = 11000;
const int MOD = int(1e9) + 7;
const double EPS = 1E-9;
const double  PI = acos(-1.0); //M_PI;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
vector<int> g[maxn];
int nn, mm;
queue<int> q;
void init();
void solve();
bool flag = 1;
int sorted = 0;
int ans = 0;
int in[maxn];
int x[maxn];
int main()
{
#ifdef LOCAL
    freopen("data.in","r",stdin);
#endif
    init();
    solve();
    return 0;
}
void init() {
  memset(in, 0, sizeof(in));

  scanf("%d %d", &nn, &mm);
  for (int i=0; i<mm; i++) {
    int f, t;
    scanf("%d %d", &f, &t);
    g[t].push_back(f);
    in[f] ++;
  }
  disp(in, 5);
  
  for (int i=1; i<=nn; i++) 
    {
      if (in[i] == 0) 
        {
          q.push(i);
          x[i] = 100;
          evar("in");
          evar(i);
          
        }
    }
  
}
void solve() {
  while(!q.empty()) 
    {
      disp(x, 5);
      
      int u = q.front();
      evar(u);

      
      q.pop();
      sorted++;
      ans += x[u];
      for (int i=0; i<g[u].size(); i++) 
        {
          int v = g[u][i];
          if (--in[v] == 0) q.push(v);
          x[v] = x[u] + 1;
        }
    }
  if (sorted == nn)
    cout<<ans<<endl;
  else
    cout<<"Poor Xed"<<endl;
  
}

