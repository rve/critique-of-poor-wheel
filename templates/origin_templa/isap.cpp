#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 210;
const int MAXM=500010;
const int inf = 2E9;

typedef struct {int v,next,val;} edge;
struct SAP {
  edge e[MAXM];
  int p[MAXN],eid;
  inline void clear(){memset(p,-1,sizeof(p));eid=0;}
  inline void insert1(int from,int to,int val) {
    e[eid].v=to;
    e[eid].val=val;
    e[eid].next=p[from];
    p[from]=eid++;
    swap(from,to);
    e[eid].v=to;
    e[eid].val=0;
    e[eid].next=p[from];
    p[from]=eid++;
  }
  inline void insert2(int from,int to,int val) {
    e[eid].v=to;
    e[eid].val=val;
    e[eid].next=p[from];
    p[from]=eid++;
    swap(from,to);
    e[eid].v=to;
    e[eid].val=val;
    e[eid].next=p[from];
    p[from]=eid++;
  }
  int n; 
  int h[MAXN];
  int gap[MAXN];
  int source,sink;
  inline int dfs(int pos,int cost) {
    if (pos==sink) {
      return cost;
    }
    int j,minh=n-1,lv=cost,d;
    for (j=p[pos];j!=-1;j=e[j].next) {
      int v=e[j].v,val=e[j].val;
      if(val>0) {
        if (h[v]+1==h[pos]) {
          if (lv<e[j].val) d=lv;
          else d=e[j].val;
          d=dfs(v,d);
          e[j].val-=d;
          e[j^1].val+=d;
          lv-=d;
          if (h[source]>=n) return cost-lv;
          if (lv==0) break;
        }
        if (h[v]<minh)  minh=h[v];
      }
    }
    if (lv==cost) {
      --gap[h[pos]];
      if (gap[h[pos]]==0) h[source]=n;
      h[pos]=minh+1;
      ++gap[h[pos]];
    }
    return cost-lv;
  }
  int run() {
    int ret=0;
    memset(gap,0,sizeof(gap));
    memset(h,0,sizeof(h));
    gap[source]=n;
    while (h[source]<n) ret+=dfs(source,inf);
    return ret;
  }
} solver;

int main() {
  int N,M;
  while (scanf("%d%d",&M,&N)!=EOF) {
    solver.source = 1;
    solver.sink = N;
    solver.n = N;
    solver.clear();
    while (M--) {
      int f,t,w;
      scanf("%d%d%d",&f,&t,&w);
      solver.insert1(f,t,w);
    }
    printf("%d\n",solver.run());
  }
  return 0;
}
