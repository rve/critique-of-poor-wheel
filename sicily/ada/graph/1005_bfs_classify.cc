#define LOCAL
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
const int MAXN = 250;
const int EXP = 10;
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;
const int TREE = 1;
const int BACK = 2;
const int DOWN = 3;
const int CROSS = 4;
int dx[] = {2,1,-1,-2,-2,-1,1,2};
int dy[] = {1,2,2,1,-1,-2,-2,-1};

struct edge{
    int x, y, s;
    edge(int _x=0,int  _y=0,int  _s=0) {
        x = _x, y=_y, s=_s;

    }
};

int color[MAXN];
int type[100000+10]; // 1 = tree,  2 = back, 3=down ,4 = crossj
string tname[] = {"Error", "Tree", "Back", "Down", "Cross"};
int d[MAXN];
int ntime = 0;
bool vis[MAXN];
bool valid(int x, int y);
int nn, mm;
int sx, sy, tx, ty;
int ret = 1;
Graph<edge> g(2000);
void dfsVisit(int u);
void dfs();
void bfs();
int makeEdge(int u, int v) {
    return u*1000 + v;
}
int main(){
#ifdef LOCAL
    freopen("data.in", "r", stdin);
#endif
    while (scanf("%d%d", &nn, &mm), nn!=0 )  {
        ret = 1;
        ntime = 0;
        cvar(nn); evar(mm);
        int a, b;
        int flag = 0;
        for (int i=0; i<mm; i++) {
            scanf("%d%d", &a, &b);
            if (a==b) flag = 1;
            cvar(a); evar(b);
            g.add(a, edge(a, b)); 
        }
        memset(vis, 0, sizeof(vis));
        memset(color, 0, sizeof(color));
        memset(type, 0, sizeof(type));
        memset(d, 0, sizeof(d));
        if (flag) ret = 1;
        else {
        dfs();
        }
        if (!ret) {
            cout<<"INVALID"<<endl;
        }
        else {
            bfs();
        }
    }
    return 0;

}
void dfs() {
    for (int i=1; i<=nn; i++) {
        color[i] = WHITE;
    }
    ntime = 0;

    for (int i=1; i<=nn; i++) {
        if (color[i] == WHITE) {
            dfsVisit(i);
        }
    }
}
void dfsVisit(int u) {
    evar(u);
    color[u] = GRAY;
    ntime ++;
    d[u] = ntime;
    for (int i=0; i<g[u].size(); i++) {
        int v = g[u][i].y;
        if (color[v] == WHITE) {
            type[makeEdge(u,v)] = TREE;
            dfsVisit(v);
        }
        else if (color[v] == GRAY) {
            ret  = 0;
            type[makeEdge(u,v)] = BACK;
        }
        else if (color[v] == BLACK) {
            if (d[u] < d[v]) {
                type[makeEdge(u,v)] = DOWN;
            }
            else {
                type[makeEdge(u,v)] = CROSS;
            }
        }
    }
    color[u] = BLACK;
    ntime ++;
}
int dep[MAXN], wid[MAXN];

void bfs() {
    memset(dep, 0,sizeof(dep));
    memset(wid, 0, sizeof(wid));
    memset(vis, 0, sizeof(vis));

    for (int k=1; k<=nn; k++) {
        queue<int> q;
        q.push(k);
        vis[k] = k;
        while(q.size()) {
            int u= q.front(); q.pop();
            for (int i=0; i<g[u].size(); i++) {
                int v = g[u][i].y;
                dep[v] = dep[u] + 1;
                vis[v] = 1;
                q.push(v);
            }
        }
    }

    int mdep = 0;
    for (int i=1; i<=nn; i++) {
        mdep = max(mdep, dep[i]);
    }
    for (int i=1; i<=nn; i++) {
        wid[dep[i]] ++;
    }
    int mwid = 0;
    for (int i=0; i<=nn; i++) {
        mwid = max(mwid, wid[i]);
    }
    cout<<mdep<<" "<<mwid<<endl;



}
