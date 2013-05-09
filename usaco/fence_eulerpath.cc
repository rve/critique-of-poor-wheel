/*
ID: jiongrr1
LANG: C++
TASK: fence
*/

#define TASK  "fence"
#define LOCAL
//#define SUBMIT
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
//compress edge  to int
int getf(int e) {
    return e/1000;
}
int gett(int e) {
    return e%1000;
}
int make_edge(int f, int t) {
    return f*1000 + t;
}

Graph<int> g(1000);
map<int, bool> mp;
stack<int> ss;
void dfs(int x) {
    int cnt = 0;
    //for each edge in adj[x]
    for (int i=0; i<g[x].size(); i++)
    {
        int t1 = g[x][i];
        int t2 = make_edge(gett(t1), getf(t1));
        cvar(t1); evar(t2);
        //assert(mp[t1] == mp[t2]);
        if (mp[t1] == 0 && mp[t2] == 0)
        {
            mp[t1] = 1;
            mp[t2] = 1;
            dfs(gett(t1));
        }
        /*
        else if (mp[t1] == 1 && mp[t2] == 1) {
        }
        else 
        {
            evar("assert failed mp[t1] != mp[t2]");
        }
        //*/
    }
    if (0 == cnt) {
        ss.push(x);
        evar(ss.top());
    }
}

const int maxn = 3000;
const int MOD = int(1e9) + 7;
const double EPS = 1E-9;
const double  PI = acos(-1.0); //M_PI;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int main()
{
#ifdef LOCAL 
    freopen(TASK ".in","r",stdin);  
#endif
#ifdef SUBMIT
    freopen(TASK ".out","w",stdout);
#endif

    int nn;
    scanf("%d", &nn);
    int de[maxn];
    int mini = INF;
    int f1 = -1, t1 = -1;
    int f, t;
    memset(de, 0, sizeof(de));
    for (int i=1; i<=nn; i++) {
        scanf("%d %d", &f, &t);
        if (f< mini) mini = f;
        if (t < mini) mini = t;
        de[f] ++;
        de[t] ++;

        g.add(f, make_edge(f,t));
        g.add(t, make_edge(t,f));
    }
    for (int i=0; i < maxn; i++) {
        if (de[i] == 1) {
            if (f1 == -1) {
                f1 = i;
            }
            else {
                t1 = i;
            }
        }
    }
    if (f1 > t1) swap(f1, t1);
    if (f1 == -1)
    dfs(mini);
    else {
        dfs(f1);
    }

    while(!ss.empty())
    {
        printf("%d\n", ss.top());
        ss.pop();
    }
    return 0;
}
