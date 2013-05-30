/*
ID: jasison2
LANG: C++
TASK: camelot
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define N 32
#define INF 0x7fffffff
#define MAX(a,b) (a)<(b)?(b):(a)
#define MIN(a,b) (a)<(b)?(a):(b)
inline int ABS(int x) { return x<0 ? -x : x; }

int r, c, n;
int dist[N][N][N][N]; // distance with knight
bool vis[N][N];
int p[N*N][2]; // king and knight position
int dx, dy; // gather position
int dir[8][2] = {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,2},{1,-2},{2,-1},{2,1}};
struct Point
{
	int x, y;
	Point() {}
	Point(int _x, int _y): x(_x), y(_y){}
	bool legal() { return x>0 && x<=c && y>0 && y<=r && !vis[x][y]; }
	void visit() { vis[x][y] = true; }
};
inline void input()
{
	cin >> r >> c;
	n = 0;
	char x;
	dx = dy = 0;
	while (cin >> x >> p[n][1])
	{
		p[n][0] = x - 'A' + 1;
		if (n)
		{
			dx += p[n][0];
			dy += p[n][1];
		}
		n ++;
	}
	if (n > 1)
	{
		dx /= (n-1);
		dy /= (n-1);
	}
}
void bfs()
{
	Point cur, nxt;
	for (int i = 1; i <= c; ++ i)
	{
		for (int j = 1; j <= r; ++ j)
		{
			for (int ix = 1; ix <= c; ++ ix)
				for (int iy = 1; iy <= r; ++ iy)
					dist[i][j][ix][iy] = 100;
			memset(vis, false, sizeof(vis));
			queue <Point> Q;
			Q.push(Point(i,j));
			vis[i][j] = true;
			dist[i][j][i][j] = 0;
			while (!Q.empty())
			{
				cur = Q.front();
				Q.pop();
				for (int k = 0; k < 8; ++ k)
				{
					nxt = Point(cur.x+dir[k][0], cur.y+dir[k][1]);
					if (nxt.legal())
					{
						dist[i][j][nxt.x][nxt.y] = dist[i][j][cur.x][cur.y] + 1;
						nxt.visit();
						Q.push(nxt);
					}
				}
			}
		}
	}
}
int calc()
{
	if (n == 1) return 0;
	int ans = INF;
	int sdx, sdy, edx, edy, sx, sy, ex, ey;
	if (n < 3)
	{
		sdx = sdy = 1;
		edx = c; edy = r;
	}
	else
	{
		sdx = MAX(1,dx-2); sdy = MAX(1,dy-2);
		edx = MIN(c,dx+2); edy = MIN(r,dy+2);
	}
	sx = MAX(1,p[0][0]-2); sy = MAX(1,p[0][1]-2);
	ex = MIN(c,p[0][0]+2); ey = MIN(r,p[0][1]+2);
	for (dx = sdx; dx <= edx; ++ dx)
	{
		for (dy = sdy; dy <= edy; ++ dy)
		{
			int tans = 0;
			for (int k = 1; k < n; ++ k)
				tans += dist[p[k][0]][p[k][1]][dx][dy];
			if (tans > ans) continue;
			for (int k = 1; k < n; ++ k)
			{
				tans -= dist[p[k][0]][p[k][1]][dx][dy];
				for (int x = sx; x <= ex; ++ x)
				{
					for (int y = sy; y <= ey; ++ y)
					{
						tans += dist[p[k][0]][p[k][1]][x][y] + dist[x][y][dx][dy];
						tans += MAX(ABS(x-p[0][0]), ABS(y-p[0][1]));
						if (tans < ans) ans = tans;
						tans -= dist[p[k][0]][p[k][1]][x][y] + dist[x][y][dx][dy];
						tans -= MAX(ABS(x-p[0][0]), ABS(y-p[0][1]));
					}
				}
				tans += dist[p[k][0]][p[k][1]][dx][dy];
			}
		}
	}
	return ans;
}
void output()
{
	printf("%d\n", calc());
}
int main()
{
	freopen("camelot.in","r",stdin);
	//freopen("camelot.out","w",stdout);
	input();
	bfs();
	output();
}
