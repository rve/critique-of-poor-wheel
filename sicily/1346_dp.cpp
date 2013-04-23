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
//#define LOCAL
#define DEBUG

#define INF 0x3f3f3f3f
#ifdef DEBUG
#define cvar(x) cerr << "<" << #x << ": " << x << ">"
#define evar(x) cvar (x) << endl
template<class T> void DISP(const char *s, T x, int n) {cerr << "[" << s << ": "; for (int i = 0; i < n; ++i) cerr << x[i] << " "; cerr << "]" << endl;}
#define disp(x,n) DISP(#x " to " #n, x, n)
#else
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

template<class edge> struct Graph
{
  vector<vector<edge> > adj;
  Graph(int n) {adj.clear (); adj.resize (n + 5);}
  Graph() {adj.clear (); }
  void resize(int n) {adj.resize (n + 5); }
  void add(int s, edge e){adj[s].push_back (e);}
  void del(int s, edge e) {adj[s].erase (find (iter (adj[s]), e)); }
  vector<edge>& operator [](int t) {return adj[t];}
};

const int maxn = 33000;
const int MOD = int(1e9) + 7;
const double EPS = 1E-9;
const double  PI = acos(-1.0); //M_PI;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int x[maxn];
struct pack {
  int v, w;
} ta[maxn][4];
int main()
{
    //evar(a);
    //disp(s, 3);
#ifdef LOCAL 
    freopen("data.in","r",stdin);  
#endif
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF) {
      int p[maxn], q[maxn], v[maxn];
      int len[maxn];
      int acc =0;
      memset(len, -1, sizeof(len));
      for (int i=1; i<=m; i++) {
        scanf("%d%d%d", &v[i], &p[i], &q[i]);
        v[i]/=10; 
        if (q[i] == 0)
          {
            len[i] = 1;
            ta[i][0].v = v[i];
            ta[i][0].w = v[i] * p[i];
          }
        else
          len[i] = 0;
      }
      for (int i=1; i<=m; i++) {
        if (len[i] == 0) {
          if (ta[q[i]][1].v == 0) {
            ta[q[i]][1].v = v[i] + ta[q[i]][0].v;
            ta[q[i]][1].w = v[i] * p[i] + ta[q[i]][0].w;
            len[q[i]] = 2;
          }
          else {
            ta[q[i]][2].v = v[i] + ta[q[i]][0].v;
            ta[q[i]][2].w = v[i] * p[i] + ta[q[i]][0].w;
            ta[q[i]][3].v = v[i] + ta[q[i]][1].v;
            ta[q[i]][3].w = v[i] * p[i] + ta[q[i]][1].w;
            len[q[i]] = 4;
          }
        }
      }
      for (int i=1; i<=m; i++)
      {
          for (int j=0; j<len[i]; j++)
          {
              {}//if (ta[i][j].v != 0) evar(ta[i][j].v);
          }
      }
      int f[maxn];
      memset(f, 0, sizeof(f));
      for (int i=1; i<=m; i++)
        if (q[i] == 0) {
          for (int j=n; j>=ta[i][0].v; j--) {
            for (int k=0; k<len[i]; k++) {
                if (j > ta[i][k].v) {
              f[j] = max(f[j], f[j - ta[i][k].v] + ta[i][k].w);
              evar(f[j]); evar(j);
                }
              //evar(f[j]);
            }}}
      //disp(f, n);
      cout<<f[n]<<endl;
}
}

