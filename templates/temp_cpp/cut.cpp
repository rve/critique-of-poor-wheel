#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

bool a[110][110];
int visit[110];
int deep[110];
int back[110];
bool cut[110];
int n,ans;


void dfs(int k,int fa,int d) {
    visit[k]=1;
    back[k]=deep[k]=d;
    int tot=0;
    for (int i=1;i<=n;i++) {
        if (a[k][i] && i!=fa && visit[i]==1)
            back[k]=min(back[k],deep[i]);
        if (a[k][i] && visit[i]==0) {
            dfs(i,k,d+1);
            tot++;
            back[k]=min(back[k],back[i]);
            if ((k==1 &&tot>1) || (k!=1 && back[i]>=deep[k]))
                if (!cut[k]) {
                    cut[k]=1;
                    ans++;
                }
          //if back[i]>deep[k] k,i is bridge;
        }
    }
    visit[k]=2;
}

int main() {
    while (1) {
        scanf("%d",&n);
        if (n==0)
            break;
        memset(a,0,sizeof(a));
        memset(back,0,sizeof(back));
        memset(cut,0,sizeof(cut));
        memset(deep,0,sizeof(deep));
        memset(visit,0,sizeof(visit));
        ans=0;
        int f;
        while (scanf("%d",&f) && f>0)  {
            while (getchar()!=10)  {
                int t;
                scanf("%d",&t);
                a[f][t]=a[t][f]=1;
            }
        }
        dfs(1,0,0);
        printf("%d\n",ans);
    }
    return 0;
}
