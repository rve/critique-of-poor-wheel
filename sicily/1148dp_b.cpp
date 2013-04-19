#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define MAXN 120
#define INF 120
using namespace std;
int main() {
    int l;
    while(scanf("%d", &l) != EOF) {
        int s, t, m;
        scanf("%d %d %d", &s, &t, &m);
        int rock[MAXN];
        rock[0] = 0;
        for (int i=1; i<=m; i++) scanf("%d", &rock[i]);
        m++;
        sort(rock, rock+m);
        int ans = 0;
        if ( s == t) {
            for (int i=1; i<m; i++) if (rock[i] % s == 0) ans++;
            printf("%d\n", ans); continue;
        }
        //    for (int i=1; i<m; i++)
        //if (rock[i] - rock[i-1] > 101) rock[i] = rock[i - 1] + 101;
        int dis[MAXN];
        for (int i=1; i<m; i++) {
            if (rock[i] - rock[i-1] > 101) dis[i] = 101;
            else dis[i] = rock[i] - rock[i-1];}
        for (int i=1; i<m; i++) rock[i] = rock[i-1] + dis[i];
        l = rock[m-1] + 101;
        bool canreach[10010], isrock[10010];
        int dp[10010];
        memset(canreach, 0, sizeof(canreach));
        memset(isrock, 0, sizeof(isrock));
        for (int i=0; i<10010; i++) dp[i] = 102;
        canreach[0] = 1; dp[0] = 0;
        for (int i=1; i<m; i++) {
            isrock[rock[i]] = 1;}
        for (int i=0; i<=l+MAXN; i++) {
            if (!canreach[i]) continue;
            for (int j=s; j<=t; j++) {
                canreach[i+j] = 1;
                if (isrock[i + j] + dp[i] < dp[i + j]) dp[i + j] = dp[i] + isrock[i + j];
            }
        }
        ans = 120;
        for (int i=l; i <= l + MAXN; i++) {ans = min(ans, dp[i]);}
        printf("%d\n", ans);
    }
}                                 
