#include <cstdio>
#include <cstring>

using namespace std;

const int maxN=1010;
const int inf=2000000000;

class DJ_heap {
public:
  int data[maxN];
  int index[maxN];
  int pos[maxN];
  int tot;
  void init (int n,int st) {
    for (int i = 2; i <= n; i++) {
      data[i] = inf;
      int now = (i == st ? 1 : i);
      index[i] = now;
      pos[now] = i;
    }
    data[1] = 0;
    index[1] = st;
    pos[st] = 1;
    tot = n;
  }
  void fix_down(int x) {
    for (int son = x + x; son <= tot; x = son, son = x + x) {
      if (son < tot && data[son+1] < data[son])
        son++;
      if (data[x] > data[son]) {
        int tmp=data[x]; data[x]=data[son]; data[son]=tmp;
        tmp=index[x]; index[x]=index[son]; index[son]=tmp;
        pos[index[x]]=x;
        pos[index[son]]=son;
      }
    }
  }
  void fix_up(int x) {
    for (int fa = x>>1; x > 1; x = fa, fa = x>>1) {
      if (data[fa] > data[x]) {
        int tmp=data[fa]; data[fa]=data[x]; data[x]=tmp;
        tmp=index[fa]; index[fa]=index[x]; index[x]=tmp;
        pos[index[x]]=x;
        pos[index[fa]]=fa;
      }
    }
  }
  void change(int x,int newdata) {
    data[pos[x]]=newdata;
    fix_up(pos[x]);
  }
  void pop(int &x,int &dist) {
    x=index[1];
    dist=data[1];
    index[1]=index[tot];
    data[1]=data[tot];
    pos[x]=0;
    pos[index[tot--]]=1;
    fix_down(1);
  }
  bool empty() {
    return tot==0;
  }
};

int a[1010][2000];
int b[1010][2000];
int dist[1010];
bool visit[1010];

DJ_heap q;

int main() {
  int n,m;
  scanf("%d%d",&m,&n);
  while (m--) {
    int f,t,cost;
    scanf("%d%d%d",&f,&t,&cost);
    a[f][++a[f][0]]=t;
    b[f][++b[f][0]]=cost;
    a[t][++a[t][0]]=f;
    b[t][++b[t][0]]=cost;
  }
  memset(dist,64,sizeof(dist));
  q.init(n,n);
  dist[n]=0;
  while (!q.empty()&&!visit[1]) {
    int v,d;
    q.pop(v,d);
    for (int i=1;i<=a[v][0];i++)
      if (!visit[a[v][i]] && dist[a[v][i]] > dist[v]+b[v][i]) {
        dist[a[v][i]] = dist[v] + b[v][i];
        q.change(a[v][i],dist[a[v][i]]);
      }
    visit[v]=1;
  }
  printf("%d\n",dist[1]);
  return 0;
}
