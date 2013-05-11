/*
ID: jiongrr1
LANG: C++
TASK: shopping
*/

#define TASK  "shopping"
#define LOCAL
#define SUBMIT
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

const int maxn = 1001;
const int MOD = int(1e9) + 7;
const double EPS = 1E-9;
const double  PI = acos(-1.0); //M_PI;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int f[6][6][6][6][6];
int nhash = 0;
int ha[maxn];
int hash(int d) {
    if (!ha[d]) ha[d] = ++nhash;
    return  ha[d];

}
struct offer {
    int p[6]; int c;
    bool e[6]; //exist
    offer() {
        memset(p, 0, sizeof(p));
        memset(e, 0, sizeof(e));
        c = 0;
    }
};
int no = 0;
offer o[150];
int r[6];
int main()
{
#ifdef LOCAL 
    freopen(TASK ".in","r",stdin);  
#endif
#ifdef SUBMIT
    freopen(TASK ".out","w",stdout);
#endif
    memset(ha, 0, sizeof(ha));

    int nn;
    cin>>nn;
    no = nn;
    for (int i=1; i<=nn; i++) {
        evar(nn);
        int tt;
        cin>>tt;
        for (int j=1; j<=tt; j++) {
            int a, b;
            cin>>a>>b;
            evar(a); evar(hash(a));
            o[i].p[hash(a)] = b;
            o[i].e[hash(a)] = 1;
        }
        int total;
        cin>>total;
        o[i].c = total;
    }

    int mm;
    cin>>mm;
    for (int i=1; i<=mm; i++) {
        int a, b, c;
        cin>>a>>b>>c;
        evar(a);
        evar(hash(a));
        r[hash(a)] = b;
        no++;
        o[no].p[hash(a)] = 1;
        o[no].e[hash(a)] = 1;
        o[no].c = c;
    }

    
    memset(f, 0x3f, sizeof(f));
    f[0][0][0][0][0] = 0;
    int a[6];
    memset(a, 0, sizeof(a));
    int acc = 1;
    for (a[1]=0;a[1]<=r[1]; a[1]++) {
        for (a[2]=0; a[2]<=r[2]; a[2]++) {
                acc++;
            for (a[3]=0; a[3]<=r[3]; a[3]++) {

                for (a[4]=0;a[4]<=r[4]; a[4]++) {

                    for (a[5]=0; a[5]<=r[5]; a[5]++) {
                        for (int i=1; i<=no; i++) {
                            bool flag = 1;
                            for (int j=1; j<=5; j++) {
                                /*
                                disp(o[i].p+1, 5);
                                disp(a+1, 5);
                                //*/
                                if (o[i].p[j] > a[j]) {flag = 0;break;}
                            }
                            //evar(f[a[1]][a[2]][a[3]][a[4]][a[5]]);
                            if (flag) {
                                //disp(a+1, 5);
                                f[a[1]][a[2]][a[3]][a[4]][a[5]]
                                    =min(f[a[1]][a[2]][a[3]][a[4]][a[5]],
                                        f[a[1]-o[i].p[1]][a[2]-o[i].p[2]]\
                                        [a[3]-o[i].p[3]]\
                                        [a[4]-o[i].p[4]][a[5]-o[i].p[5]] + o[i].c);
                            }
                        }
                    }
                }
            }
        }
    }
    int ret = f[r[1]][r[2]][r[3]][r[4]][r[5]];
    disp(r+1, 5);
    cout<<ret<<endl;
    

}
