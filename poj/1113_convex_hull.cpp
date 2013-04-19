#include<iostream>
#include<string>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#define PI 3.14159265358979
#define MAXN 10010
#define INF 0x3f3f3f3f
using namespace std;
struct point{
    int x, y;
} p[MAXN], bag[MAXN];
int len, n;
int cross(point o, point t1, point t2) {
    return (t1.x - o.x) * (t2.y -o.y) - (t1.y-o.y) * (t2.x - o.x);
}
int compare(const void* t1, const void* t2) {
    point *p1 = (point*) t1;
    point *p2 = (point*) t2;
    if (p1->y == p2->y) return p1->x - p2->x;
    return p1->y - p2->y;
}
void make_bag()
{
    int i, j;
    qsort(p, n, sizeof(point), compare);
    bag[0] = p[0];
    len = 1;
    for (i=1; i<n; i++)
    {
        while(len >=2 && cross(bag[len-2], bag[len-1], p[i]) <=0) len--;
        bag[len++] = p[i];
    }
    j = len + 1;
    for (i=n-1; i>=0; i--) 
    {
        while(len >= j && cross(bag[len-2], bag[len-1], p[i]) <= 0) len--;
        bag[len++] = p[i];
    }
    len--;
}
double dist(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y-b.y) * (a.y -b.y));
}
int main()
{
    int L;
    scanf("%d %d", &n, &L);
    for (int i=0; i<n; i++)
    {
        scanf("%d %d", &p[i].x, &p[i].y);
    }
    make_bag();
    double ans = 0;
    for (int i=1; i<len; i++)
        ans += dist(bag[i], bag[i-1]);
    ans += dist(bag[len-1], bag[0]);
    ans += 2 * PI * L;
    printf("%d\n", (int) (ans + 0.5));

}
