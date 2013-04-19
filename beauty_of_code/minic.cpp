#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define N 120000 
struct POINT {
    double x, y;
} p[N];
int n;
inline double dist(const POINT &a, const POINT &b) {
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
POINT circumcenter(POINT &a, POINT &b, POINT &c) {
    POINT ret;
    double a1=b.x-a.x, b1=b.y-a.y, c1=(a1*a1+b1*b1)/2;
    double a2=c.x-a.x, b2=c.y-a.y, c2=(a2*a2+b2*b2)/2;
    double d = a1*b2 - a2*b1;
    ret.x = a.x + (c1*b2-c2*b1)/d;
    ret.y = a.y + (a1*c2-a2*c1)/d;
    return ret;
}
void solve() {
    random_shuffle(p, p+n);  //随机化序列，std里面的随机函数
    POINT c;
    double r = 0;
    for (int i=1; i<n; i++) {
        if (dist(p[i], c) <= r) continue;
        c = p[i];
        r = 0;
        for (int j=0; j<i; j++) {
            if (dist(p[j], c) <= r) continue;
            c.x = (p[i].x+p[j].x)/2;
            c.y = (p[i].y+p[j].y)/2;
            r = dist(p[j], c);
            for (int k=0; k<j; k++) {
                if (dist(p[k], c) <= r) continue;
                c = circumcenter(p[i], p[j], p[k]);
                r = dist(p[i], c);
            }
        }
    }
    //printf("%.6lf %.6lf %.6lf\n", c.x, c.y, r);
    printf("%.6lf\n", c.x);
}
int main() {
    int T;
    scanf("%d", &T);
    for (int k=0; k<T; k++) {
    scanf(" %d", &n);
    {
        printf("Case #%d: ",k+1);
        for (int i=0; i<n; i++)
            scanf(" %lf %lf", &p[i].x, &p[i].y);
        for (int i=n + 0; i<n + n; i++)
        {
            p[i].x = p[i-n].x; p[i].y = -1 *p[i-n].y;
        }
        n = 2*n;
        solve();
    }}
    return 0;
}
