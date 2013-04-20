#include <iostream>
#include<cstring>
#include<cstdio>
using namespace std;

const int maxn=150000;
const int maxm=2000000;
const int inf=1<<30;
struct edge{int from, to, val, next;}e[maxm];;
int v[maxn], que[maxn], dis[maxn],len;
void init()
{
    len=0;
    memset(v, -1, sizeof(v)); 
}
void insert(int from, int to, int va)
{
    e[len].from = from, e[len].to = to; e[len].val = va;
    e[len].next = v[from];v[from] = len++;
    e[len].from = to, e[len].to = from; e[len].val = 0;
    e[len].next = v[to];v[to] = len++;
}
int Dinic(int n, int s, int t)
{
    int ans = 0;
    while(true)
    {
        int head, tail, id,i;
        head = tail = 0; que[tail++] = s;
        memset(dis, -1, sizeof(dis)); dis[s] = 0;
        while(head < tail)
        {
            id = v[que[head++]];
            while(id != -1)
            {
                if (e[id].val > 0 && dis[e[id].to] == -1)
                {
                    dis[e[id].to] = dis[e[id].from] + 1;
                    que[tail++] = e[id].to;
                    if (e[id].to == t)
                    {
                        head = tail;
                        break;
                    }
                }
                id = e[id].next;
            }
        }
        if (dis[t] == -1) break;
        id = s, tail = 0;
        while(true)
        {
            if (id == t) // 找到一条增广路
            {
                int flow =inf,fir;
                for(i = 0; i < tail; i++)
                    if (e[que[i]].val < flow)
                    {
                        fir = i;
                        flow = e[que[i]].val;
                    }
                    for(i = 0; i < tail; i++)
                        e[que[i]].val -= flow, e[que[i] ^ 1].val += flow;
                    ans += flow; tail = fir; id = e[que[fir]].from;
            }
            id = v[id];
            while(id != -1)
            {
                if (e[id].val > 0 && dis[e[id].from] + 1 == dis[e[id].to])
                    break;
                id = e[id].next;
            }
            if (id != -1)
            {
                que[tail++] = id;
                id = e[id].to;
            }
            else
            {
                if (tail == 0) break;
                dis[e[que[tail - 1]].to] = -1;
                id = e[que[--tail]].from;
            }
        }
    }
    return ans;
}
int main()
{
    int t,n,m,a,b,c,cas;
    while (scanf("%d",&t)!=EOF)
    {
        cas = 0;
        while (t--)
        {
            printf("Case #%d:\n",++cas);
            init();
            scanf("%d%d",&n,&m);
            int cur = 0;
            int acc =0;
            while (m--)
            {
                scanf("%d%d%d",&a,&b,&c);
                insert(a-1,b-1,c);
                insert(b-1, a-1, c);
                int ans = Dinic(n, 0, n-1);
                ++acc;
                if (ans > cur) 
                {
                    printf("%d %d\n", acc, ans -cur);
            //        cur =ans;
                }
            }
        }
    }
    return 0;
}
