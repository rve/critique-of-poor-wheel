//#define LOCAL
//#define DEBUG

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

const int maxn = 110;
const int MOD = int(1e9) + 7;
const double EPS = 1E-9;
const double  PI = acos(-1.0); //M_PI;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
int vis[maxn];
int color[maxn];
int main()
{
#ifdef LOCAL 
    freopen("data.in","r",stdin);  
#endif
    memset(color, 0, sizeof(color));
    memset(vis, 0, sizeof(vis));
    Graph<int> g(maxn);
    int nn, mm;
    scanf("%d %d", &nn, &mm);
    for (int i=1; i<=mm; i++) {
        int f, t;
        scanf("%d %d", &f, &t);
        g.add(f, t);
        g.add(t, f);
    }
    //show 
    {
        for (int i=0; i<g.adj.size(); i++) {
            for (int j=0; j<g[i].size(); j++) {
                cvar(i); cvar(j);
                evar(g[i][j]);
            }
        }
    }
    for (int i=1; i<=nn; i++) {

        if (!color[i]) {
            memset(vis, 0, sizeof(vis));
            queue<int> q;
            q.push(i);
            color[i] = i;
            while(q.size()) {
                int cur = q.front(); q.pop();
                vis[cur] = 1;
                for (int k=0; k<g[cur].size(); k++) {
                    int t = g[cur][k];
                    if (!vis[t] && !color[t]) {
                        color[t] = color[cur];
                        q.push(t);
                    }
                }

            }
        }
    }
    disp(color, nn+1);
    int ans[maxn];
    memset(ans, 0, sizeof(ans));
    for (int i=1; i<=nn; i++) {
        evar(color[i]);
        //ans[color[i]] += 1; //??
        int dum = color[i];
        ans[dum] ++;
    }
    disp(ans, nn+1);
    int ret = 0;
    for (int i=1; i<=nn; i++) {
        if (ans[i]) ret++;
    }
    cout<<ret<<endl;
    return 0;
        
}
