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

const int maxn = 60;
const int MOD = int(1e9) + 7;
const double EPS = 1E-9;
const double  PI = acos(-1.0); //M_PI;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

struct point {
    int x, y;
    point(int x=-1, int y=-1) : x(x), y(y) {};
};
struct edge {
    int u, v;
    float d;
    edge(int u = -1, int v = -1, float d = 0) : u(u), v(v), d(d) {
    }
};
float cal(point a, point b) {
    return sqrt((a.x -b.x) * (a.x - b.x) + (a.y-b.y) * (a.y - b.y));
}
int nn, mm;
int root[maxn];
void Init() {
    for (int i=1; i<=nn; i++) {
        root[i] = i;
    }
}
void Union(int a, int b) {
    root[a] = b;
}
int Find(int x) {
    if (x != root[x])  {
        root[x] = Find(root[x]);
    }
    return root[x];
}
edge e[maxn*maxn + 100];
bool cmp(edge a, edge b) {
    return a.d < b.d;
}
point p[maxn];
int ss, tt;
int main()
{
#ifdef LOCAL 
    freopen("data.in","r",stdin);  
#endif
    while(scanf("%d", &nn), nn!=0) {
        scanf("%d %d",&ss, &tt);
        for (int i=1; i<=nn; i++) {
            scanf("%d %d", &p[i].x, &p[i].y);
        }
        int acc = 0;
        int sacc;
        for (int i=1; i<=nn; i++) {
            for (int j=i+1; j<=nn; j++) {
                e[acc].d = cal(p[i], p[j]);
                e[acc].u = i, e[acc].v = j;
                if ((i== ss && j == tt) || (i==tt && j == ss)) {
                    swap(e[0], e[acc]);
                }
                acc++;
            }
        }
        sort(e+1, e+acc, cmp);
        // krustakl
        float ans = 0;
        Init();
        for (int i=0; i<acc; i++) {
            int x = Find(e[i].u), y = Find(e[i].v);
            float d = e[i].d;
            if (x != y) {
                Union(x, y);
                ans += d;
            }
        }
        printf("%.2f\n", ans);

    }
}
