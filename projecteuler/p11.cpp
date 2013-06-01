//#define LOCAL
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

const int maxn = 110000;
const int MOD = int(1e9) + 7;
const double EPS = 1E-9;
const double  PI = acos(-1.0); //M_PI;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int x[][20] =
{{8,02,22,97,38,15,00,40,00,75,04,05,07,78,52,12,50,77,91,8,},
{49,49,99,40,17,81,18,57,60,87,17,40,98,43,69,48,04,56,62,00,},
{81,49,31,73,55,79,14,29,93,71,40,67,53,88,30,03,49,13,36,65,},
{52,70,95,23,04,60,11,42,69,24,68,56,01,32,56,71,37,02,36,91,},
{22,31,16,71,51,67,63,89,41,92,36,54,22,40,40,28,66,33,13,80,},
{24,47,32,60,99,03,45,02,44,75,33,53,78,36,84,20,35,17,12,50,},
{32,98,81,28,64,23,67,10,26,38,40,67,59,54,70,66,18,38,64,70,},
{67,26,20,68,02,62,12,20,95,63,94,39,63,8,40,91,66,49,94,21,},
{24,55,58,05,66,73,99,26,97,17,78,78,96,83,14,88,34,89,63,72,},
{21,36,23,9,75,00,76,44,20,45,35,14,00,61,33,97,34,31,33,95,},
{78,17,53,28,22,75,31,67,15,94,03,80,04,62,16,14,9,53,56,92,},
{16,39,05,42,96,35,31,47,55,58,88,24,00,17,54,24,36,29,85,57,},
{86,56,00,48,35,71,89,07,05,44,44,37,44,60,21,58,51,54,17,58,},
{19,80,81,68,05,94,47,69,28,73,92,13,86,52,17,77,04,89,55,40,},
{04,52,8,83,97,35,99,16,07,97,57,32,16,26,26,79,33,27,98,66,},
{88,36,68,87,57,62,20,72,03,46,33,67,46,55,12,32,63,93,53,69,},
{04,42,16,73,38,25,39,11,24,94,72,18,8,46,29,32,40,62,76,36,},
{20,69,36,41,72,30,23,88,34,62,99,69,82,67,59,85,74,04,36,16,},
{20,73,35,29,78,31,90,01,74,31,49,71,48,86,81,16,23,57,05,54,},
{01,70,54,71,83,51,54,69,16,92,33,48,61,43,52,01,89,19,67,48}};

int main()
{
#ifdef LOCAL 
    freopen("data.in","r",stdin);  
#endif
    int64 best = 0;
    for (int i=0; i<20; i++) {
        for (int j=0; j<20; j++) {
            int64 r1, r2, r3, r4;
            r1=r2=r3=r4=1;
            for (int k=0; k<4 ; k++) {
                if (j+k < 20)
                r1 *= x[i][j+k];
                if (i+k < 20)
                r2 *= x[i+k][j];
                if (i+k < 20 && j+k < 20)
                r3 *= x[i+k][j+k];
                if (i-k >= 0 && j+k < 20)
                r4 *= x[i-k][j+k];


               best = max(best, r1, r2);
               best = max(best, r3, r4);
            }
        }
    }
    cout<<best<<endl;
}
