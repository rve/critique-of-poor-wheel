/*
ID: jiongrr1
LANG: C++
TASK: camelot
*/

#define TASK  "camelot"
#define SUBMIT
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

const int kx[] = {2,1,-1,-2,-2,-1,1,2};//knight jump
const int ky[] = {1,2,2,1,-1,-2,-2,-1};
const int maxn = 33;
const int inf = 1234567;
struct point {
    int x, y, s;
    point(int _x=0, int _y=0, int _s=0) {
        x=_x, y=_y, s=_s;
    }
};
point saber, k[maxn * maxn];
bool inline isValid(point& p);
void input();
void init();
int rr, cc; // rows , cols
int cnt = 0; // cnt of knights
int ta[maxn][maxn][maxn][maxn]; //table for precalculate dist
point get[maxn*maxn]; //point to get saber on
int nget = 0;
void bfs();
void solve();

int main()
{
#ifdef LOCAL 
    freopen(TASK ".in","r",stdin);  
#endif
#ifdef SUBMIT
    freopen(TASK ".out","w",stdout);
#endif
    input();
    init();
    //special judge
    if (0 == cnt)  {
        cout<<0<<endl;
    }
    else if (rr <3 && cc < 3) {
        cout<<1<<endl;
    }
    else
    {
        bfs();
        solve();
    }
    return 0;

}
void input() {
    cin>>rr>>cc;
    char a; int b;
    cin>>a>>b;
    saber.x = a - 'A' + 1; saber.y = b;
    saber.s = 0;
    k[0] = saber;
    while(cin>>a>>b) {
        k[++cnt].x = a - 'A' + 1;
        k[cnt].y = b;
    }
}
bool inline isValid(point& p) {
    return p.x >0 && p.x <= cc && p.y>=1 && p.y<=rr;
}
void init() {
    for (int i=1; i<=rr; i++) {
        for (int j=1; j<=cc; j++) {
            for (int k=1; k<=rr; k++) {
                for (int l=1; l<=cc; l++)
                {
                    ta[i][j][k][l] = inf;
                }
            }
        }
    }
    int sax = max(1, saber.x-2);
    int say = max(1, saber.y - 2);
    int tax = min(cc, saber.x+2);
    int tay = min(rr, saber.y + 2);
    for (int i=sax; i<=tax; i++) {
        for (int j=say; j<=tay; j++) {
            get[++nget] = point(i, j);
        }
    }
}
void solve() {
    int ret = inf, xpick, ypick, xga, yga;
    xga = yga = xpick = ypick = -1;  // for debug 
    for (int i=1; i<=nget; i++) {
        int foo = max(abs(saber.y - get[i].y), abs(saber.x - get[i].x));
        for (int sy=1; sy<=rr; sy++) {
            for (int sx=1; sx<=cc; sx++) {
                int ans = 0, bestfs = inf;
                for (int id=1; id<=cnt; id++) {
                    ans += ta[k[id].y][k[id].x][sy][sx];
                    // calcucate the extra expense to get saber first and go to gather point than direct
                    int tmpfs = ta[k[id].y][k[id].x][get[i].y][get[i].x]
                        + foo + ta[get[i].y][get[i].x][sy][sx]
                        - ta[k[id].y][k[id].x][sy][sx];
                    if (tmpfs < bestfs) {
                        bestfs = tmpfs;
                        xpick = get[i].x; ypick = get[i].y;
                    }
                }
                if (ans + bestfs < ret) {
                    ret = ans + bestfs;
                    xga = sx, yga = sy;
                }
            }
        }
    }
    cout<<ret<<endl;
}
void bfs() {
    for (int sy=1; sy<=rr; sy++) {
        for (int sx=1; sx<=cc; sx++) {
            ta[sy][sx][sy][sx] = 0;
            point u = point(sx, sy); u.s=0;
            queue<point> q;
            q.push(u);
            int vis[maxn][maxn]; memset(vis, 0, sizeof(vis));
            vis[u.y][u.x] = 1;
            while(q.size()) {
                point cur = q.front(); q.pop();
                for (int i=0; i<8; i++) {
                    point tmp;
                    tmp.y = cur.y + ky[i];
                    tmp.x = cur.x + kx[i];
                    tmp.s = cur.s + 1;
                    if (isValid(tmp) && vis[tmp.y][tmp.x] == 0) {
                        vis[tmp.y][tmp.x] = 1;
                        ta[sy][sx][tmp.y][tmp.x] = tmp.s;
                        q.push(tmp);
                    }
                }
            }
        }
    }
}
