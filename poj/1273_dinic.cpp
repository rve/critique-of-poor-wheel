//#define LOCAL
#include <queue>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 250;
const int inf = 0x3f3f3f3f;
int mp[maxn][maxn];
int dist[maxn];
int nn, mm;
int bfs();
void init();
int find(int u, int flow);
void dinic();
int main()
{
#ifdef LOCAL 
    freopen("data.in","r",stdin);  
#endif
    while(scanf("%d%d", &mm, &nn) != EOF) {
        memset(mp, 0, sizeof(mp));
        for (int i=1; i<=mm; i++) {
            int u,v,flow;
            scanf("%d%d%d", &u, &v, &flow);
            mp[u][v] += flow;
        }
        dinic();
    }
    return 0;
}
int bfs() {
    for (int i=0; i<maxn; i++) dist[i] = -1;
    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while (q.size()) {
        int u = q.front(); q.pop();
        for (int i=1; i<=nn; i++) {
            if (dist[i] <0 && mp[u][i] > 0 ) {
                dist[i] = dist[u] + 1;
                q.push(i);
            }
        }
    }
    if (dist[nn] <= 0) return 0;
    else return 1;
}
int find(int u, int mflow) {
    int tflow = 0;
    if (u == nn) {
        return mflow;
    }
    for (int i=1; i<=nn; i++) {
        if (mp[u][i] > 0 && dist[i] == dist[u] + 1) {
            if (tflow = find(i, min(mflow, mp[u][i]))) // can reach sink
            {
                mp[u][i] -= tflow;
                mp[i][u] += tflow;
                return tflow;
            }
        }
    }
    return 0;
}
void dinic() {
    int ans = 0, tmp;
    while(bfs()) {
        while (tmp = find(1, inf)) {
            ans += tmp;
        }
    }
    printf("%d\n", ans);
}
