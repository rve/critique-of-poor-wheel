#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n,m,ans,t,f;
int maxf[210][210],flow[210][210],cost[210][210];
int fa[210],dist[210];
bool inque[210];

inline int abs(int a) {return a > 0 ? a : -a ;}
void init() {
  int a[210][2]={0},b[210][2]={0},s=0,sa=0,sb=0;
  memset(maxf,0,sizeof(maxf));
  memset(flow,0,sizeof(flow));
  memset(cost,0,sizeof(cost));
  for (int i=1;i<=n;i++){
    for (int j=1;j<=m;j++) {
      char tt;
      cin>>tt;
      if (tt=='H') {
        a[++sa][0]=i;
        a[sa][1]=j;
      }
      if (tt=='m') {
        b[++sb][0]=i;
        b[sb][1]=j;
      }
    }
  }
  s=sa;
  for (int i = 1;i <= s; i++) {
    for (int j = 1;j <= s; j++) {
      cost[i][s+j] = abs(a[i][0]-b[j][0])+abs(a[i][1]-b[j][1]);
      cost[s+j][i] = cost[i][s+j];
      maxf[i][s+j] = 1;
    }
  }
  for (int i = 1; i <= s; i++)
    maxf[0][i]=maxf[s+i][s+s+1]=1;
  n = t = s + s + 1;
  f = 0;
  ans = 0;
}

inline int value(int i,int j) {
  return flow[j][i] > 0 ? -cost[i][j] : cost[i][j];
}

bool spfamark() {
  memset(fa,0,sizeof(fa));
  memset(inque,0,sizeof(inque));
  memset(dist, 0x3f, sizeof(dist));
  queue<int> q;
  q.push(f); inque[f] = true; dist[f]=0;
  while (!q.empty()) {
    int now = q.front(); q.pop(); inque[now] = false;
    for (int i = 0; i <= n;i++)
      if ((maxf[now][i] - flow[now][i] > 0)
          && dist[now] + value(now,i) < dist[i]){
        dist[i] = dist[now] + value(now,i);
        fa[i] = now;
        if (!inque[i]) {
          inque[i]=1;
          q.push(i);
        }
      }
  }
  return dist[t] != 0x3f3f3f3f;
}


int main() {
  while (cin >> n >> m && n && m) {
    init();
    while (spfamark()) {
      for(int i = t; i != f; i = fa[i]) {
        ans+=value(fa[i],i);
        flow[fa[i]][i]++;
        flow[i][fa[i]]--;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
