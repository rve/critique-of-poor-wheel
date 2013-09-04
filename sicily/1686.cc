#define LOCAL
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

#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
const int M = 20020;
int mx[M<<2];
void pushup(int rt) {
    mx[rt] = max(mx[rt<<1], mx[rt<<1|1]);
}
void build(int l, int r, int rt) {
    if (l == r) {
        scanf("%d", &mx[rt]);
        return;
    }
    int m = (l+r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int p, int sc, int l, int r, int rt) {
    if (l == r) {
        mx[rt] = sc;
        return;
    }
    int m = (l+r) >> 1;
    if (p <= m) {
        update(p, sc, lson);
    }
    else {
        update(p, sc, rson);
    }
    pushup(rt);

}
int query(int L, int R, int l, int r, int rt) {
    if (L <= l && R >= r) {
        return mx[rt];
    }
    int m = (r + l ) >> 1;
    int ret = 0;
    if (L <= m) {
        ret = max(ret,query(L, R, lson));
    }
    if (R > m) {
        ret = max(ret,query(L, R, rson));
    }
}

int main()
{
#ifdef LOCAL 
    freopen("data.in","r",stdin);  
#endif
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF) {
        build(1,n,1);
        for (int i=1; i<=m; i++) {
            char op[10];
            int a, b;
            scanf("%s%d%d", op, &a, &b);
            if (op[0] == 'U') {
                update(a, b, 1, n, 1);
            }
            if (op[0] == 'Q') {
                int ret = query(a, b, 1, n, 1);
                printf("%d\n", ret);
            }
            
        }
    }
}
