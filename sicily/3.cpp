#include <stdio.h>
#include <stdlib.h>
 
#define MAX 200010
 
/* 定义边(x,y)，权为w */
typedef struct
{
	int x, y;
	int w;
}edge;
 
edge e[MAX];
/* rank[x]表示x的秩 */
int rank[MAX];
/* father[x]表示x的父节点 */
int father[MAX];
int sum;
 
/* 比较函数，按权值(相同则按x坐标)非降序排序 */
int cmp(const void *a, const void *b)
{
	if ((*(edge *)a).w == (*(edge *)b).w)
	{
		return (*(edge *)a).x - (*(edge *)b).x;
	}
	return (*(edge *)a).w - (*(edge *)b).w;
}
 
/* 初始化集合 */
void Make_Set(int x)
{
	father[x] = x;
	rank[x] = 0;
}
 
/* 查找x元素所在的集合,回溯时压缩路径 */
int Find_Set(int x)
{
	if (x != father[x])
	{
		father[x] = Find_Set(father[x]);
	}
	return father[x];
}
 
/* 合并x,y所在的集合 */
void Union(int x, int y, int w)
{
 
	if (x == y) return;
	/* 将秩较小的树连接到秩较大的树后 */
	if (rank[x] > rank[y])
	{
		father[y] = x;
	}
	else
	{
		if (rank[x] == rank[y])
		{
			rank[y]++;
		}
		father[x] = y;
	}
	sum += w;
}
 
/* 主函数 */
int main()
{
	int i, n, m;
	int x, y;
	int chx, chy;
 
	/* 读取边的数目 */
	while(scanf("%d%d", &m, &n), m!=0 && n!=0)
   {
   int acc = 0;
 
	/* 读取边信息并初始化集合 */
	for (i = 0; i < n; i++)
	{
		scanf("%d %d %d", &chx, &chy, &e[i].w);
		e[i].x = chx ;
		e[i].y = chy ;
		Make_Set(i);
      acc += e[i].w;
	}
 
	/* 将边排序 */
	qsort(e, n, sizeof(edge), cmp);
 
	sum = 0;
 
	for (i = 0; i < n; i++)
	{
		x = Find_Set(e[i].x);
		y = Find_Set(e[i].y);
		if (x != y)
		{
			//printf("%c - %c : %d\n", e[i].x + 'A', e[i].y + 'A', e[i].w);
			Union(x, y, e[i].w);
		}
	}
 
	printf("%d\n", acc - sum);
   }
	//system("pause");
	return 0;	
}
