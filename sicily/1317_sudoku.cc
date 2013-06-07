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

const int nn = 11;
const int mm= 110;
const int MOD = int(1e9) + 7;
const double EPS = 1E-9;
const double  PI = acos(-1.0); //M_PI;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

char mp[nn][nn];
char ans[nn][nn];
bool row[nn][nn], col[nn][nn], blo[nn][nn];
inline int block(int x, int y) {
    return (x-1)/3*3 + (y-1)/3 + 1;
}
int todo;
int cnt;
struct point {
    int x, y, prio, b;
    point(int x = -1, int y = -1) : x(x) , y(y) {
        b = block(x, y);
    }
    void calc() {
        int cnt = 0;
        for (int i=1; i<=9; i++) {
               if(!row[x][i] && !col[y][i] && !blo[b][i])
                cnt ++;
            }
        prio = cnt;
    }
} p[mm];
bool cmp(point a, point b) {
    return a.prio < b.prio;
}
void dfs(int d);
int main()
{
#ifdef LOCAL 
    freopen("data.in","r",stdin);  
#endif
    int cas;
    scanf("%d", &cas);
    for (int time=1; time<=cas; time++) {
        if (time != 1) printf("\n");
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(blo, 0, sizeof(blo));
        todo = cnt = 0;
        for (int i=1; i<=9; i++) {
            scanf("%s", mp[i] + 1);
            for (int j=1; j<=9; j++) {
                if (mp[i][j] == '_') {
                    p[todo] = point(i, j);
                    todo++;
                }
                else {
                    int t = mp[i][j] - '0';
                    row[i][t] = 1;
                    col[j][t] = 1;
                    blo[block(i,j)][t] = 1;
                }
            }
        }
        for (int i=0; i<todo; i++) p[i].calc();
        sort(p, p+todo, cmp);
        dfs(0);
        if (cnt == 0) printf("Puzzle %d has no solution\n", time);  
        else if (cnt == 1)  
        {  
            printf("Puzzle %d solution is\n", time);  
            for (int i = 1; i <= 9; ++ i)  
                printf("%s\n", ans[i]+1);  
        }  
        else printf("Puzzle %d has %d solutions\n", time, cnt);  
    }
}
void dfs(int d) {
    if ( d == todo) {
        cnt ++;
        if (cnt == 1)
            memcpy(ans, mp, sizeof(mp));
        return;
    }
    int x = p[d].x, y = p[d].y, b = p[d].b;
    for (int k=1; k<=9; k++) {
        if (!col[y][k] && !row[x][k] && !blo[b][k]){
            col[y][k] = row[x][k] = blo[b][k] = 1;
            mp[x][y] = '0' + k;
            dfs(d+1);
            col[y][k] = row[x][k] = blo[b][k] = 0;
        }
    }
}
