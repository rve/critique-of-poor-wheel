
#define TASK  "msquare"
//#define LOCAL
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
#define debug(...) printf( __VA_ARGS__) 
#define cvar(x) cerr << "<" << #x << ": " << x << ">"
#define  simplevar(x) cerr << x << " "
#define evar(x) cvar (x) << endl
template<class T> void DISP(const char *s, T x, int n) {cerr << "[" << s << ": "; for (int i = 0; i < n; ++i) cerr << x[i] << " "; cerr << "]" << endl;}
#define disp(x,n) DISP(#x " to " #n, x, n)
#else
#define  simplevar(...) ({})
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

const int maxn = 30;
const int MOD = int(1e9) + 7;
const double EPS = 1E-9;
const double  PI = acos(-1.0); //M_PI;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};



struct Data {
    int m[5][5];
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
    int tmp = d.m[3][1]; d.m[3][1] = d.m[2][1];
    d.m[2][1] = d.m[2][2];
    d.m[2][2] = d.m[3][2];
    d.m[3][2] = tmp;
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

void dispex(Data& d);
const int times = 150;
int vis[times];
int lenvis = 0;
map<int64, bool> mp;
bool avail(Data& d);
int main()
{
#ifdef LOCAL 
    freopen(TASK ".in","r",stdin);  
#endif
#ifdef SUBMIT
    freopen(TASK ".out","w",stdout);
#endif
    int mm;
    while(cin>>mm, mm!=-1) {
        memset(vis, 0, sizeof(vis));
        mp.clear();
        lenvis = 0;
        Data t, d;
        for (int i=1; i<=4; i++) {
            cin>>t.m[i][1];
            d.m[i][1] = i;
            evar(t.m[i][1]);
        }
        for (int i=1; i<=4; i++) {
            cin>>t.m[i][2];
        }
        for (int i=4; i>=1; i--) {
            //cin>>t.m[i][2];
            d.m[i][2] = 9 - i;
            evar(t.m[i][1]);
        }
        evar(d.len);
        dispex(d);
        evar(t.len);
        dispex(t);
        queue<Data> q;
        q.push(d);
        int count = INF;
        evar(!is_equal(q.front(), t));
        memset(vis, 0,sizeof(vis));
        while(!is_equal(q.front(), t) && (count > 0)) {
            count --;

            Data _d = q.front();

            //dispex(_d);
            q.pop();
            Data r;
            r = swap(_d);
            if (avail(r))
                q.push(r);
            r = rshift(_d);
            if (avail(r))
                q.push(r);
            r = rotate(_d);
            if (avail(r))
                q.push(r);
        }
        if (is_equal(q.front(), t)) {
            Data ans = q.front();
            ans.s[ans.len] = '\0';
            if (ans.len > mm) {
                cout<<-1<<endl;
                continue;
            }
            cout<<ans.len<<" ";
            cout<<ans.s<<endl;
        }
        else { cout<<-1<<endl;}
    }
    return 0;


}
void dispex(Data& d)
{
    simplevar("\n");
    for (int i=1; i<=4; i++) {
        simplevar(d.m[i][1]);
        //cvar(d.m[i][1]);
    }
    simplevar("\n");
    for (int i=1; i<=4; i++) {
        simplevar(d.m[i][2]);
    }
    simplevar("\n");
}
bool avail(Data& d)
{
    int64 seq=0;
    int64 m = 1;
    for (int i=1; i<=4; i++) {
        seq += m * d.m[i][1]; 
        m *=10;
    }
    for (int i=1; i<=4; i++) {
        seq += m * d.m[i][2];
        m *= 10;
    }
    if (mp[seq]) return 0;
    else {
        mp[seq] = 1;
        return 1;
    }
}
