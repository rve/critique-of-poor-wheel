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

const int maxn = 11;
const int MOD = int(1e9) + 7;
const double EPS = 1E-9;
const double  PI = acos(-1.0); //M_PI;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

bool col[maxn][maxn], row[maxn][maxn], blo[maxn][maxn];
int x[maxn*maxn], y[maxn*maxn], cnt;
int todo;
char mp[maxn][maxn];
char ans[maxn][maxn];
bool dfs(int d);
void showv();
int main()
{
#ifdef LOCAL 
    freopen("data.in","r",stdin);  
#endif
    int cas;
    cin>>cas;
    while(cas --) {
        todo = cnt = 0;
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(blo, 0, sizeof(blo));
        memset(ans, '*', sizeof(ans));
        for (int i=1; i<=9; i++) {
            for (int j=1; j<=9; j++) {
                cin>>mp[i][j];
                char c = mp[i][j];
                if (mp[i][j] == '0') {
                    x[todo] = i;
                    y[todo] = j;
                    todo++;
                }
                else {
                    row[i][c-'0'] = 1;
                    col[j][c-'0'] = 1;
                    blo[(i-1)/3*3 + (j-1)/3 + 1][c-'0'] = 1;
                }
            }
        }
        //showv();
        if (dfs(0))  {
            for (int i=1; i<=9; i++) {
                for (int j=1; j<=9; j++) {
                        cout<<mp[i][j];
                }
                cout<<endl;
            }
        }
        else {
            cout<<"failed"<<endl;
        }

    }
    return 0;
}
bool dfs(int d) {
    if (d == todo) {
        cnt ++; return true;
    }
    int i=x[d], j = y[d];
    for (int k=1; k<=9; k++) {
        if (!row[i][k] && !col[j][k] && !blo[(i-1)/3*3 + (j-1)/3 + 1][k]) {
            mp[i][j] = k+'0';
            row[i][k] = col[j][k] = blo[(i-1)/3*3 + (j-1)/3 + 1][k] = 1;
            if (dfs(d+1)) return true;
            row[i][k] = col[j][k] = blo[(i-1)/3*3 + (j-1)/3 + 1][k] = 0;
        }
    }
    return false;
}
void showv() {
    //*/debug

    cout<<" row --"<<endl;
    for (int i=1; i<=9; i++) {
        for (int j=1; j<=9; j++) {
            cout<<row[i][j];
        }
        cout<<endl;
    }
    cout<<" col -- "<<endl;
    for (int i=1; i<=9; i++) {
        for (int j=1; j<=9; j++) {
            cout<<col[i][j];
        }
        cout<<endl;
    }
    cout<<" blo -- "<<endl;
    for (int i=1; i<=9; i++) {
        for (int j=1; j<=9; j++) {
            cout<<blo[i][j];
        }
        cout<<endl;
    }
    //*/

}
void showm() {
    cout<< "-- mp --"<<endl;
    for (int i=1; i<=9; i++) {
        for (int j=1; j<=9; j++) {
        }
    }
}
