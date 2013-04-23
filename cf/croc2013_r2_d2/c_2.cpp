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

#define MAXN 10010
#define INF 0x5f3759df //for magic

//#define LOCAL
#define DEBUG
#ifdef DEBUG
#define cvar(x) cerr << "<" << #x << ": " << x << ">"
#define evar(x) cvar (x) << endl
//template<class T> void DISP(const char *s, T x, int n) {cerr << "[" << s << ": "; for (int i = 0; i < n; ++i) cerr << x[i] << " "; cerr << "]" << endl;}
#define disp(x,n) DISP(#x " to " #n, x, n)
#else
#define cvar(...) ({})
#define evar(...) ({})
#define disp(...) ({})
#endif
#define car first
#define cdr second
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

int main()
{
#ifdef LOCAL 
    freopen("data.in","r",stdin);  
#endif 
    int  n;
    cin>>n;
    string a, b;
    cin>>a>>b;
    int mm, m1,m2;
    mm=m1=m2=0;
    for (int i=0; i<a.size(); i++)
    {
        if (a[i] == '1' && b[i] == '1') mm++;
        if (a[i] == '1' && b[i] == '0') m1++;
        if (a[i] == '0' && b[i] == '1') m2++;
    }
    while(m1>0 && m2> 0) {m1--, m2--;};
    int an = 0, bn = 0;
    if (mm&1) {an++;  if (m2 & 1) bn++;}
    else { if (m1 &1) an++;}
    an +=m1/2, bn +=m2/2;
    if (an > bn) cout<<"First"<<endl;
    else if (an == bn) cout<<"Draw"<<endl;
    else cout<<"Second"<<endl;
    


}
