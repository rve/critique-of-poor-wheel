#include<iostream>
#include<cstdio>
#include<cstring>
using namespace  std;
const int maxn = 1100;
int nn, mm;
int adj[maxn][maxn];
int vis[maxn], mat[maxn];
bool aupath(int u);
int hungary();
void input();
int main() {
    while (cin>>nn>>mm) {
    input();
    cout<<hungary()<<endl;
    }
    return 0;
}
void input() {
    for (int i=1; i<=nn; i++) {
        cin>>adj[i][0];
        for (int k=1; k<=adj[i][0]; k++) {
            cin>>adj[i][k];
        }
    }
}
int hungary() {
    memset(mat, 0, sizeof(mat));
    int match = 0;
    for (int i=1; i<=nn; i++) {
        memset(vis, 0, sizeof(vis));
        if (aupath(i)) {
            match++;
        }
    }
    return match;
}
bool aupath(int u) {
    for (int i=1; i<=adj[u][0]; i++) {
        int v = adj[u][i];
        if (!vis[v]) {
            vis[v] = 1;
            if (mat[v] == 0 || aupath(mat[v])) {
                mat[v] = u;
                return true;
            }
        }
    }
    return false;
}
