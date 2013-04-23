#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <climits>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>

#define MAXN 3210
#define INF 0x5f3759df //for magic
#define LOCAL
//#define DEBUG
#ifdef DEBUG
#define debug(...) printf( __VA_ARGS__) 
#else
#define debug(...)
#endif

using namespace std;
const int MOD = int(1e9) + 7;
const double  PI = acos(-1.0); //M_PI;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

template<class T> inline T min(T a, T b, T c){return min(min(a, b), c);}
template<class T> inline T max(T a, T b, T c){return max(max(a, b), c);}
template<class T> inline T min(T a, T b, T c, T d){return min(min(a, b), min(c, d));}
template<class T> inline T max(T a, T b, T c, T d){return max(max(a, b), max(c, d));}
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline T cub(T a){return a*a*a;}

struct sub{
    int v, w;
};
struct indata{
    int a, b, c;
};
#define MAXC 65
int main()
{
#ifdef LOCAL 
    freopen("data.in","r",stdin);  
#endif
    int N, m;
    while(scanf("%d %d", &N, &m) != EOF) {
        N /= 10;
        indata temp[MAXC];
        int f[MAXN];
        int map[MAXC * 3];
        int vis[MAXC * 3];
        int acc = 0;
        sub s[MAXC * 3];
        int hash[MAXN][3];
        memset(hash, 0, sizeof(hash));
        memset(f, 0, sizeof(f));
        for (int i=1; i<=m; i++) {
            scanf("%d%d%d", &temp[i].a, &temp[i].b, &temp[i].c);
            temp[i].a /= 10; // refinement
            if (temp[i].c != 0 )
                if (hash[temp[i].c][1] == 0) {
                    hash[temp[i].c][1] = i;
                }
                else {
                    hash[temp[i].c][2] = i;
                }
            else {
                acc ++;
                map[acc] = acc;
                s[acc].v = temp[i].a;
                s[acc].w = temp[i].a * temp[i].b;
            }
        }
        for (int i=1; i<=m; i++){
            debug("%d %d %d ", temp[i].a, temp[i].b, temp[i].c);}
        debug("\n");
        for (int i=1; i<=m; i++) {
            if (hash[i][1] != 0 ) {
                acc++;
                s[acc].v = s[i].v + temp[hash[i][1]].a;
                s[acc].w = s[i].w + temp[hash[i][1]].a * temp[hash[i][1]].b;
            }
            if (hash[i][2] != 0 ) {
                acc++;
                s[acc].v = s[i].v + temp[hash[i][2]].a;
                s[acc].w = s[i].w + temp[hash[i][2]].a * temp[hash[i][1]].b;
            }
            if (hash[i][1] != 0 && hash[i][2] != 0 ) {
                acc++;
                s[acc].v = s[i].v + temp[hash[i][1]].a 
                    + temp[hash[i][2]].a;
                s[acc].w = s[i].w + temp[hash[i][1]].a * temp[hash[i][1]].b
                    + temp[hash[i][2]].a * temp[hash[i][2]].b;
            }
        }

        for (int i=1; i<=acc; i++)
            for (int j = N; j>=s[i].v; j--)
                f[j] = max(f[j], f[j - s[i].v] + s[i].w);
        int ret = 0;
        for (int i=0; i<=N; i++)
            if (f[i] > ret) ret = f[i];

        cout<<ret*10<<endl;


    }

}
