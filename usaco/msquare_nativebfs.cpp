/*
ID: jiongrr1
LANG: C++
TASK: msquare
*/

#define TASK  "msquare"
//#define LOCAL
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

const int maxn = 100;
const int MOD = int(1e9) + 7;
const double EPS = 1E-9;
const double  PI = acos(-1.0); //M_PI;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int x[maxn];
struct Data {
    int m[3][5];
    char s[maxn];
    int len;
    Data() {s[0] = '\0'; len = 0; memset(m, 0, sizeof(m));}
};
Data rshift(Data& d1) {
    Data d2 = d1;
    int tmp[3];
    tmp[1] = d1.m[4][1]; tmp[2] = d1.m[4][2];
    for (int i=4; i>=2; i--) {
        d2.m[i][1] = d2.m[i-1][1];
        d2.m[i][2] = d2.m[i-1][2];
    }
    d2.m[1][1] = tmp[1]; d2.m[1][2] = tmp[2];
    d2.s[d2.len++] = 'B';
    return d2;
}
Data rotate(Data& _d) {
    Data d = _d;
    int tmp = d.m[1][3];
    d.m[1][3] = d.m[1][2];
    d.m[1][2] = d.m[2][2];
    d.m[2][2] = d.m[2][3];
    d.m[2][3] = tmp;
    d.s[d.len++] = 'C';
    //d.s += "C";
    return d;
}
Data swap(Data& _d) {
    Data d = _d;
    for (int i=1; i<=4; i++) {
        swap(d.m[i][1], d.m[i][2]);
    }
    d.s[d.len++] = 'A';
    //d.s += "A";
    return d;
}
bool is_equal(Data& a, Data& b) {
    bool flag = 1;
    for (int i=1; i<=4; i++) {
        for (int j=1; j<=2; j++) {
            if (a.m[i][j] != b.m[i][j]) {
                flag = 0; break;
            }}}
    return flag;
}

int main()
{
#ifdef LOCAL 
    freopen(TASK ".in","r",stdin);  
#endif
#ifdef SUBMIT
    freopen(TASK ".out","w",stdout);
#endif
    Data t, d;
    for (int i=1; i<=4; i++) {
        cin>>t.m[i][1];
        d.m[i][1] = i;
    }
    for (int i=4; i>=1; i--) {
        cin>>t.m[i][2];
        d.m[i][2] = 8 - i;
    }
    for (int i=1; i<=4; i++) {
    cvar(d.m[i][1]);}
    evar("");
    for (int i=1; i<=4; i++) {
    cvar(d.m[i][2]);}
    evar("");
    for (int i=1; i<=4; i++) {
    cvar(t.m[i][1]);}
    evar("");
    for (int i=1; i<=4; i++) {
    cvar(t.m[i][2]);}
    evar("");
    //t.s = d.s = "";
    queue<Data> q;
    q.push(d);
    int count = 10;
    while(!is_equal(q.front(), t) && count-- >= 0) {
        Data _d = q.front();
        Data r;
        r = rshift(_d);
        q.push(r);
        r = rotate(_d);
        q.push(r);
        r = swap(_d);
        q.push(r);
    }
    if (count) {
        Data ans = q.front();
        ans.s[ans.len] = '\0';
        cout<<ans.len<<endl;
        cout<<ans.s<<endl;
    }
    else  cout<<"None"<<endl;
    return 0;

}
