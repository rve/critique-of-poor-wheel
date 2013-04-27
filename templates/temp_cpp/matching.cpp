#include <cstdio>
#include <cstring>

bool adj[555][555];
bool visit[555];
int match[555];
int n;

bool dfs(int now) {
    for (int i = 1; i <= n; i++) {
        if (visit[i] == false && adj[now][i]) {
            visit[i] = true;
            int tt = match[i];
            match[i] = now;
            if (tt == -1 || dfs(tt)) return true;
            match[i] = tt;
        }
    }
    return false;
}

int main() {
    int m;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < m; i++) {
        int f,t; scanf("%d%d",&f,&t);
        adj[f][t] = true;
    }
    int ans = 0;
    memset(match,0xff,sizeof(match));
    for (int i = 1; i <= n; i++) {
        memset(visit,0,sizeof(visit));
        if (dfs(i)) ans ++;
    }
    printf("%d\n",ans);
    return 0;
}
