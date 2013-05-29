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

const int maxn = 1100;
const int MOD = int(1e9) + 7;
const double EPS = 1E-9;
const double  PI = acos(-1.0); //M_PI;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
int nn, mm;
char m[maxn][maxn];

int x[maxn];
struct point {
    int x, y;
    char c;
    int s;
    point(int x=0, int y=0) : x(x), y(y) {
        c = '*';
        s = 0;
    }
} start;
bool isValid(int, int);
bool isEdge(int , int);
deque<point> q;
deque<point> fire;
int ans = 0;
void updateFire();
int main()
{
#ifdef LOCAL 
    freopen("data.in","r",stdin);  
#endif
    int cas;
    cin>>cas;
    while(cas --) {
        ans = -1;
        q.clear();
        cin>>mm>>nn;
        for (int i=1; i<=nn; i++) {
            for (int j=1; j<=mm; j++) {
                cin>>m[i][j];
                if (m[i][j]=='@') {
                    start.x = i;
                    start.y = j;
                    start.c = '@';
                }
                else if (m[i][j] == '*') {
                    q.push_back(point(i, j));
                }
            }
        }
    start.s = 0;
    q.push_front(start);

    int vis[maxn][maxn];
    memset(vis, 0, sizeof(vis));
    vis[start.x][start.y] = 1;
    int cnt = 10000000;
    while(q.size() && cnt--) {
        point u = q.front();
        q.pop_front();
        if (u.c == '@') {

            if (isEdge(u.x, u.y)) {
                q.clear();
                  ans = u.s + 1;
                break;

            }
            int flag = 1;
            for (int i=0; i<4; i++) {
                point v = u;
                v.x = u.x + dx[i];
                v.y = u.y + dy[i];
                v.s = u.s + 1;
                if (isValid(v.x, v.y) && vis[v.x][v.y] == 0) {
                    cvar(v.x); cvar(v.y); evar(v.s);
                    vis[v.x][v.y] = 1;
                    flag = 0;
                    q.push_back(v);
                }
                
            }
        }
        if (u.c == '*') {
            for (int i=0; i<4; i++) {
                point v = u;
                v.x = u.x + dx[i];
                v.y = u.y + dy[i];
                if (isValid(v.x, v.y)) {
                    m[v.x][v.y] = '*';
                    q.push_back(v);
                }
            }


        }
    }
    if (ans == -1) {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else {
        cout<<ans<<endl;
    }
    }
}
bool isValid(int x, int y) {
    return x>=1 && y>=1 &&  y <= mm &&  x <= nn && m[x][y] != '#' && m[x][y] != '*';
}
bool isEdge(int x, int y) {
    return (x == 1 || x == nn ) || (y == 1 ||  y == mm);
}                                 
void updateFire() {
    while(!fire.empty()) {
        
    }
}
