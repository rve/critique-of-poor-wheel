/*
ID: jiongrr1
LANG: C++
TASK: butter
*/

#define TASK  "butter"
#define LOCAL
//#define SUBMIT
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

const int maxn = 110000;
const int MOD = int(1e9) + 7;
const double EPS = 1E-9;
const double  PI = acos(-1.0); //M_PI;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int MAXN = 900;
const int MAXM = 3000;
const int EXP = 10;
const int INF = 25000000;
 
int edges; 
struct EDGE{
  int n;
  int d;
  EDGE *nxt;
}pool[MAXM*2+EXP];
EDGE lnk[MAXN+EXP];
 
void addEdge (int _f, int _t, int _d){
  pool[edges].n = _t;
  pool[edges].d= _d;
  pool[edges].nxt = lnk[_f].nxt;
  lnk[_f].nxt = &pool[edges];
  edges++;
}
int cow_at[MAXN];
 
int nn;
int pp;
int mm;
 
bool inQ[MAXN+EXP];
int dist[MAXN][MAXN+EXP];
 
void spfa(int s, int k){ 
  for(int i = 0; i <= nn; i++){
    inQ[i] = 0;             
    dist[k][i] = INF;
  }
  queue<int> Q; Q.push(k); // change s to k 
  inQ[k] = 1; dist[k][k] = 0;
  while(Q.size()){
    int now = Q.front(); Q.pop();
    inQ[now] = 0;
    for(EDGE* tmp = lnk[now].nxt; tmp; tmp = tmp->nxt){
      if(dist[k][now] + tmp->d < dist[k][tmp->n]){
        dist[k][tmp->n] = dist[k][now] + tmp->d;
        if(!inQ[tmp->n]) { 
          Q.push(tmp->n);
          inQ[tmp->n] = 1;
        }
      }
    }
  }
}
 
int main(){


#ifdef LOCAL 
    freopen(TASK ".in","r",stdin);  
#endif
#ifdef SUBMIT
    freopen(TASK ".out","w",stdout);
#endif
    edges = 0;
    
    scanf("%d%d%d", &pp, &nn, &mm); 
    for(int i = 1; i <= pp; i++) scanf("%d", &cow_at[i]);
    for(int i = 1; i <= nn; i++) lnk[i].nxt = 0; 
    for(int i = 1; i <= mm; i++){
      int aa,bb,dd; scanf("%d%d%d", &aa, &bb, &dd);
      addEdge(aa, bb, dd);
      addEdge(bb, aa, dd);
    }
    for (int i=1; i<=nn; i++)
    spfa(1,i);    

    int ret = INF;
    for (int i=1; i<=nn; i++)
    {
        int sum = 0;
        for (int j=1; j<=pp; j++)
        {
            sum += dist[i][cow_at[j]];
        }
        if (sum < ret) ret = sum;
        evar(sum);
    }
    cout<<ret<<endl;
  return 0;
}
