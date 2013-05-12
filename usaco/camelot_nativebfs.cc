/*
ID: jiongrr1
LANG: C++
TASK: camelot
*/

#define TASK  "camelot"
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

const int maxn = 901;
const int MOD = int(1e9) + 7;
const double EPS = 1E-9;
const double  PI = acos(-1.0); //M_PI;
struct point {
    int x, y, s, fs;
    // fs means steps from saber (for saber, it means steps to other p) \
    // calculate from saber's array(d[0]), which combines horse move and saber move
    // s mean (minial) steps to other points (generate by bfs with horse move)
    point(int _x=0, int _y=0, int _s=0, int _fs=INF) {
        x=_x, y=_y, s=_s, fs=_fs;
    }
};
point saber, k[maxn];
int d[maxn][31][31];
int ds[maxn][31][31];
const int dx[] = {2,1,-1,-2,-2,-1,1,2};//knight jump
const int dy[] = {1,2,2,1,-1,-2,-2,-1};
const int sx[] = {1,0,-1,-1.-1,0,1,1}; //saber move
const int sy[] = {1,1,1,0,-1,-1,-1,0};
bool inline isValid(point& p);
void inline bfs(int x);
void ff(); // calculate saber's minimal steps to all point on the board
int rr, cc;
/*
 * frist find saber's (minimal) steps to all points
 * then calculate knight's steps to all points and sum them on board
 * then ans = min(saber_step + kn_step_sum) on the (rr * cc) board
 
   //*/

void show(int a[][31]);
int main()
{
#ifdef LOCAL 
    freopen(TASK ".in","r",stdin);  
#endif
#ifdef SUBMIT
    freopen(TASK ".out","w",stdout);
#endif
    cin>>rr>>cc;
    char a; int b;
    cin>>a>>b;
    cvar(a); evar(b);
    saber.x = a - 'A' + 1; saber.y = b;
    saber.fs = 0;
    saber.s = 0;
    int cnt = 1;
    k[0] = saber;
    while(cin>>a>>b) {
        k[cnt].x = a - 'A' + 1;
        k[cnt].y = b;
        cnt++;
    }
    memset(d, 0x3f, sizeof(d));
    memset(ds, 0x3f, sizeof(ds));
    bfs(0);
    ff();
    show(d[0]);
    for (int i=1; i<cnt; i++) {
        bfs(i);
    }
    int des1[31][31];
    int des2[31][31];
    memset(des1, 0, sizeof(des1));
    memset(des2, 0x3f, sizeof(des2));
    for (int m=1; m<cnt; m++)
        for (int i=1; i<=rr; i++) {
            for (int j=1; j<=cc; j++) {
                des1[i][j] += d[m][i][j];
     //           evar(m);
     //           show(d[m]);
     //           show(d[1]);
     //           show(des1);
     //           show(d[m]);
     //           cvar(i); evar(j);
                des2[i][j] = min(des2[i][j], ds[m][i][j]);
            }}
    point best;
    best.s = INF * 2;
    for (int i=1; i<=rr; i++) {
        for (int j=1; j<=cc; j++) {
            if (best.s > (des1[i][j] + des2[i][j])) {
                best.x = j;
                best.y = i;
                best.s = des1[i][j] + des2[i][j];
                if (des1[i][j] >= INF) 
                    best.s = des2[i][j]; //.....sigh
            }}}

    cout<<best.s<<endl;
    return 0;

}
void inline bfs(int x) {
    int vis[31][31];
    memset(vis, 0, sizeof(vis));
    queue<point> q;
    d[x][k[x].y][k[x].x] = 0;
    k[x].fs = d[0][k[x].y][k[x].x];
    ds[x][k[x].y][k[x].x] = d[0][k[x].y][k[x].x];
    //evar(k[x].fs);
    q.push(k[x]);
    while(q.size()) {
        point cur = q.front(); q.pop();
        vis[cur.y][cur.x] = 1;
        for (int i=0; i<8; i++) {
            point tmp;
            tmp.x = cur.x + dx[i];
            tmp.y = cur.y + dy[i];
            tmp.s = cur.s + 1;
            if (isValid(tmp) && (!vis[tmp.y][tmp.x])) {
                if (x != 0) {
                    tmp.fs = min(d[0][tmp.y][tmp.x], cur.fs);
                    ds[x][tmp.y][tmp.x] = min(ds[x][tmp.y][tmp.x], tmp.fs);
                }
                q.push(tmp);
                if (d[x][tmp.y][tmp.x] > tmp.s) {
                    d[x][tmp.y][tmp.x] = tmp.s;}
            }

        }

    }
}
bool isValid(point& p) {
    return p.x >0 && p.x <= cc && p.y>=1 && p.y<=rr;
}
void ff() {
    bool vis[31][31];
    memset(vis,0, sizeof(vis));
    queue<point> q;
    saber.fs = 0;
    saber.s = INF;
    q.push(saber);
    //evar("saber: ");
    while(q.size()) {
        point cur = q.front(); q.pop();
        vis[cur.y][cur.x] = 1;
        for (int i=0; i<8; i++) {
            point tmp;
            tmp.x = cur.x + sx[i];
            tmp.y = cur.y + sy[i];
            tmp.fs = min(tmp.fs, cur.fs+1);
            //evar(tmp.fs);
            if (isValid(tmp) &&vis[tmp.y][tmp.x] == 0) {
                q.push(tmp);
                if (tmp.fs < d[0][cur.y][cur.x]) {
                    d[0][cur.y][cur.x] = tmp.fs;}
            }
        }}
}
void show(int a[][31]) 
{
    for (int i=1; i<=rr; i++) {
        for (int j=1; j<=cc; j++) {
            cvar(a[i][j]);
        }
        evar("\n");
    }
}
