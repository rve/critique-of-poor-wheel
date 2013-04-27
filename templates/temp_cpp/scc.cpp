#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>

using namespace std;

vector<int> a[10010];
vector<int> b[10010];
stack<int> tt;
int fa[10010];
int d[10010];
int size[10010];
bool visit[10010];
int n,m;

void dfs(int k) {
  visit[k]=1;
  for (int i=0;i<a[k].size();i++)
    if (!visit[a[k][i]])
      dfs(a[k][i]);
  tt.push(k);
}

void dfs(int k,int FA) {
  fa[k]=FA;
  size[FA]++;
  visit[k]=1;
  for (int i=0;i<b[k].size();i++)
    if (!visit[b[k][i]])
      dfs(b[k][i],FA);
}

int main() {
  scanf("%d%d",&n,&m);
  for (int i=0;i<m;i++) {
    int f,t;
    scanf("%d%d",&f,&t);
    a[f].push_back(t);
    b[t].push_back(f);
  }
  memset(visit,0,sizeof(visit));
  for (int i=1;i<=n;i++)
    if (!visit[i])
      dfs(i);
  memset(visit,0,sizeof(visit));
  int s=0;
  for (;!tt.empty();tt.pop())
    if (!visit[tt.top()])
      dfs(tt.top(),++s);
  for (int i=1;i<=n;i++) {
    int f=fa[i];
    for (int j=0;j<b[i].size();j++) {
      int t=fa[b[i][j]];
      if (f!=t)
        d[t]++;
    }
  }
  vector<int> ans;
  for (int i=1;i<=s;i++)
    if (d[i]==0)
      ans.push_back(size[i]);
  if (ans.size()==1)
    printf("%d\n",ans[0]);
  else
    puts("0");
  return 0;
}
