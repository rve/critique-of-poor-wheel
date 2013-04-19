
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 200010;
const long long INF = 10000000000;
int n, m, id, head[N];
long long sum;
struct edge{
    int t, next;
    int l;
}e[N*2];
long long prim() {
    int u = n - 1, v;
    long long mi, ans = 0, d[N];
    bool vis[N];
    for ( int i = 0; i < n; ++i ) d[i] = INF;
    memset(vis, 0, sizeof(vis));
    d[0] = 0;
    
    for ( int t = 0; t <= u; ++t ) {
        mi = INF;
        for ( int i = 0; i < n; ++i ) if ( !vis[i] && d[i] < mi ) {
            v = i, mi = d[i];
        }
            //printf("%d %lld\n", v, mi);
        if ( mi == INF ) break;
        ans += mi;
        vis[v] = true;
        for ( int i = head[v]; i != -1; i = e[i].next ) {
            int x = e[i].t, c = e[i].l;
            if ( !vis[x] && d[x] > c ) d[x] = c;
        }
    }
    return ans;
}
void add( int u, int v, int c ) {
    e[id].next = head[u], e[id].t = v, e[id].l = c, head[u] = id++;
    e[id].next = head[v], e[id].t = u, e[id].l = c, head[v] = id++;
}

int main()
{
    while ( scanf("%d%d", &n, &m) != EOF && !( m == 0 && n == 0 ) ) {
        sum = 0, id = 0;
        for ( int i = 0; i <= n; ++i ) head[i] = -1;
        while ( m-- ) {
            int s, t, l;
            scanf("%d%d%d", &s, &t, &l);
            sum += l;
            add( s, t, l );
        }
        printf("%lld\n", sum - prim());
    }
}
