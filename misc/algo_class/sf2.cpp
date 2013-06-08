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

 
const int MAXN = 1010;
const int MAXM = 20010;
const int EXP = 10;
const int INF = 8;
 
int edges; 
struct EDGE{
  int n;
  int d;
  EDGE *nxt;
}pool[MAXM*2+EXP];
EDGE lnk[MAXN+EXP];
 
void addEdge (int _f, int _t, int _d){
  pool[edges].n = _t;
  pool[edges].d= _d;
  pool[edges].nxt = lnk[_f].nxt;
  lnk[_f].nxt = &pool[edges];
  edges++;
}
 
int nn;
int mm;
 
bool inQ[MAXN+EXP];
int dist[MAXN+EXP];
 
void spfa(int s){ 
  for(int i = 0; i <= nn; i++){
    inQ[i] = 0;             
    dist[i] = INF;
  }
  queue<int> Q; Q.push(s); 
  inQ[s] = 1; dist[s] = 0;
  while(Q.size()){
    int now = Q.front(); Q.pop();
    inQ[now] = 0;
    for(EDGE* tmp = lnk[now].nxt; tmp; tmp = tmp->nxt){
      if(dist[now] + tmp->d < dist[tmp->n]){
        dist[tmp->n] = dist[now] + tmp->d;
        if(!inQ[tmp->n]) { 
          Q.push(tmp->n);
          inQ[tmp->n] = 1;
        }
      }
    }
  }
}
inline int64 hash(char s[11]) {
    int64 ans = 0;
    for (int i=0; s[i] != '\0'; i++) {
        ans = s[i] -'A' + 1 + ans * 10;
    }
    return ans;
}
 
int main(){
#ifdef LOCAL
    freopen("data.in", "r", stdin);
#endif
    int ans[MAXN];
    while(scanf("%d", &nn)) {
        if (nn == 0) break;
        char s[MAXN][12];
        memset(ans, 0x3f, sizeof(ans));
        map<int64, int> mp;
        for (int i=1; i<=nn; i++) {
            scanf("%s\n", s[i]);
            mp[hash(s[i])] = i;
        }
        scanf("%d", &mm);
        //cin>>mm;
        edges = 0;
        for(int i = 1; i <= nn; i++) lnk[i].nxt = 0; 
        for(int i = 1; i <= mm; i++){
            char s1[12], s2[12];
            //string s1, s2;
            //cin>>s1>>s2;
            scanf("%s %s\n", s1, s2);
            int aa,bb,dd; 
            aa = mp[hash(s1)]; bb = mp[hash(s2)]; dd= 1;
            addEdge(aa, bb, dd);
            addEdge(bb, aa, dd);
        }

        int ans = -1;
        for (int k=1; k<=nn; k++) {
            spfa(k);    
            for (int i=1; i<=nn; i++) {
                    ans = max(ans, dist[i]);
            }
        }
        if (ans >= INF) cout<<-1<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}
