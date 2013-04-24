#include<cstdio>
#include<algorithm>
using namespace std;

struct node
{
	int x,y,t;
}origin[100010],tosort[100010];

int fa[100010],s[100010],e[100010],deep[100010],dis[100010],l[100010],r[100010],in[100010];
int n,total;

bool cmp(struct node a,struct node b)
{
	return a.x < b.x;
}

void dfs(int k)
{
    total++;
    l[k] = total;
    r[k] = total;
	for (int i = s[k] ; i <= e[k] ; i++)
	{
		int next = tosort[i].y;
		if (fa[next] == -1)
		{
			fa[next] = k;
			deep[next] = deep[k] + 1;
			dis[next] = dis[k] + tosort[i].t;
			dfs(next);
         r[k] = r[next];
		}
	}
}

int lowbit(int t)
{
    return t & (-t);
}

int sum(int t)
{
    int ans = 0;
    while (t > 0)
    {
        ans += in[t];
        t -= lowbit(t);
    }
    return ans;
}

void update(int t,int v)
{
    while (t <= n)
    {
        in[t] += v;
        t += lowbit(t);
    }
}

int dist(int st,int ed)
{
	int i = st , j = ed;
	while (deep[i] > deep[j]) i = fa[i];
	while (deep[j] > deep[i]) j = fa[j];
	while (fa[i] != fa[j])
	{
		i = fa[i];
		j = fa[j];
	}
   i = fa[i];
   int dis1 = dis[st] + sum(st);
   int dis2 = dis[i] + sum(i);
   int dis3 = dis[ed] + sum(ed);
   return dis1 - dis2 + dis3 - dis2;
}

int main()
{
	int q,st;
	scanf("%d%d%d",&n,&q,&st);
	for (int i = 1 ; i < n ; i++)
	{
		scanf("%d%d%d",&origin[i].x,&origin[i].y,&origin[i].t);
		tosort[i-1].x = origin[i].x;
		tosort[i-1].y = origin[i].y;
		tosort[i-1].t = origin[i].t;
	}
	sort(tosort,tosort+n-1,cmp);
	for (int i = 1 ; i <= n ; i++)
	{
		fa[i] = -1;
		s[i] = n;
		e[i] = -1;
	}
	for (int i = 0 ; i < n-1 ; i++)
	{
		if (i < s[tosort[i].x]) s[tosort[i].x] = i;
		if (i > e[tosort[i].x]) e[tosort[i].x] = i;
	}
	fa[1] = 1;
	deep[1] = 1;
	dis[1] = 0;
   total = 0;
	dfs(1);
   for (int i = 1 ; i <= n ; i++) in[i] = 0;
	while (q--)
	{
		int op;
		scanf("%d",&op);
		if (op == 0)
		{
			int ed;
			scanf("%d",&ed);
			printf("%d\n",dist(st,ed));
			st = ed;
		}
		if (op == 1)
		{
			int num,newt;
			scanf("%d%d",&num,&newt);
         int ox = origin[num].x;
			int oy = origin[num].y;
         int dif = newt - origin[num].t;
         origin[num].t = newt;
			update(l[oy],dif);
         update(r[oy]+1,-dif);
		}
	}
	return 0;
}
