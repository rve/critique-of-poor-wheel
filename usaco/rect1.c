/*
ID: jiongrr1
LANG: C
TASK: rect1
*/
#include<stdio.h>
#include<string.h>
#define MAXN 10010
int x1[MAXN], yy1[MAXN], x2[MAXN], y2[MAXN];
int color[MAXN], area[MAXN];
int n;
void cover(int lx, int ly, int ux, int uy, int i, int c)
{
    while ( i < n && ( ux <= x1[i] || uy <= yy1[i] || lx >= x2[i] || ly >= y2[i]))
        i++;
    if ( i == n) { area[c] += (ux - lx) * (uy - ly); return;}

    if (lx < x1[i]) { cover(lx, ly, x1[i], uy, i+1, c); lx = x1[i];}
    if (ly < yy1[i]) { cover(lx, ly, ux, yy1[i], i+1, c); ly = yy1[i];}
    if (ux > x2[i]) { cover(x2[i], ly, ux, uy, i+1, c); ux = x2[i];}
    if (uy > y2[i]) { cover(lx, y2[i], ux, uy, i+1, c); uy = y2[i];}

}
int main()
{
    freopen("rect1.in", "r", stdin);
    freopen("rect1.out", "w", stdout);
    memset(area, 0, sizeof(area));
    memset(color, 0, sizeof(color));
    x1[0] = yy1[0] = 0;
    scanf("%d %d %d",&x2[0], &y2[0], &n);
    color[0] = 1;
    n++;
    int i;
    for(i=1; i<n; i++)
        scanf("%d %d %d %d %d", &x1[i], &yy1[i], &x2[i], &y2[i], &color[i]);
    for(i=n-1; i>=0; i--)
        cover(x1[i], yy1[i], x2[i], y2[i], i+1, color[i]);
    for(i=0; i<MAXN; i++)
        if (area[i])
            printf("%d %d\n", i, area[i]);

    

}
