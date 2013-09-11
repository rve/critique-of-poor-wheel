#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define FILL(x) memset(x, 0, sizeof(x));
#define PB push_back
const int M = 10010;

int main()
{
#ifdef LOCAL 
    freopen("data.in","r",stdin);  
    //freopen("data.out", "w", stdout):
#endif
    int T;
    cin>>T;
    while(T--) {
        vector<int> g[M];
        int f, t;
        int nn;
        int deg[M];
        FILL(deg);
        scanf("%d", &nn);
        for (int i=0; i<nn-1; i++) {
            scanf("%d%d", &f, &t);
            g[f].PB(t);
            g[t].PB(f);
            deg[f] ++;
            deg[t] ++;

        }
        queue<int> q;
        bool vis[M];
        FILL(vis);
        for (int i=1; i<=nn; i++) {
            if (deg[i] == 1) 
                q.push(i);
        }
        while(!q.empty()) {
            int f = q.front(); q.pop();
            if (deg[f] == 1 && !vis[f]) {
                int t = g[f][0];
                vis[t] = vis[f] = 1;
                g[f].clear();
                for (int i=0; i<g[t].size(); i++) {
                    int v = g[t][i];
                    for (int j=0; j<g[v].size(); j++) {
                        int x = g[v][j];
                        if (x == t) {
                            g[v].erase(g[v].begin() + j);
                            deg[v] --;
                        }
                    }
                    if (deg[v] == 1) 
                        q.push(v);
                }
            }
        }
        bool flag = 1;
        for (int i=1; i<=nn; i++) {
            if (vis[i] != 1)
                flag = 0;
        }
        if (flag) cout<<"Yes\n";
        else cout<<"No\n";
    }
}                                 
