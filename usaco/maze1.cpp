/*
ID: jiongrr1
LANG: C++
TASK: maze1
*/
#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
#define MAXN 210
#define INF 0x3f3f3f3f
using namespace std;
int d[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int best = 0;
bool vis[MAXN][MAXN];
int m[MAXN][MAXN];
int H, W;
struct p
{
    p(int x = 0, int y = 0, int p = 0) : x(x), y(y), path(p) {};
    int x, y;
    int path;
};
void solve(int x, int y);
char a[MAXN][MAXN];
int main()
{
    memset(m, 0, sizeof(m));
    freopen("maze1.in", "r", stdin);
    freopen("maze1.out", "w", stdout);
    scanf("%d%d", &W, &H);
    H = 2 * H + 1; W = 2 * W + 1;
    for (int i = 0; i < H; i++)
    {
        getchar();//
        for (int j = 0; j < W; j++)
        {
            scanf("%c", &a[i][j]);
        }
    }
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
        {
            if (a[i][j] == ' ')
            {
                for(int k=0; k<4; k++)
                {
                    int ii = i + d[k][0];
                    int jj = j + d[k][1];
                    if ( ii >= H || jj >= W || ii < 0 || jj < 0)
                    {
                        solve(i, j);
                    }
                }

            }
        }

    for(int i = 0; i < H; i++)
        for(int j = 0; j < W; j++)
            if (m[i][j] >= best)
                best = m[i][j];

    printf("%d\n", best/2);

}
inline void solve(int x, int y)
{
    queue<p> q;
    q.push(p(y, x, 1));
    memset(vis, 0, sizeof(vis));
    vis[y][x] = 1;

    while(!q.empty())
    {
        p cur = q.front();
        q.pop();
        if (m[cur.y][cur.x] == 0 || cur.path < m[cur.y][cur.x])
            m[cur.y][cur.x] = cur.path;
        for(int i=0; i < 4; i++)
        {
            int xx = cur.x + d[i][0];
            int yy = cur.y + d[i][1];
            if ( xx >= 0 && yy >= 0 && xx < W && yy < H && a[yy][xx] == ' ')
            {
                if (!vis[yy][xx])
                {
                    vis[yy][xx] = 1;
                    q.push(p(xx, yy, cur.path+1));


                }

            }
        }
    }
}
