#include <cstdio>
#include <cstring>
#include <queue>

using std::queue;

void toInt(char s[]) {
  for (int i = 0; s[i]; i++) {
    if (s[i]=='A') s[i]='0';
    if (s[i]=='G') s[i]='1';
    if (s[i]=='T') s[i]='2';
    if (s[i]=='C') s[i]='3';
  }
}

struct trie{
  trie *next[4];
  trie *fail;
  bool isend;
};

trie pool[1010];
trie *head;
trie *root;

void insert(char s[]) {
  trie *now=root;
  for (;;) {
    if (s[0]==0) {
      now->isend=1;
      return;
    }
    int tt=s[0]-'0';
    if (now->next[tt]==NULL)
      now->next[tt]=++head;
    now=now->next[tt];
    s++;
  }
}

void buildFaliure() {
  queue<trie*> q;
  for (int i=0;i<4;i++)
    if (root->next[i]) 	{
      root->next[i]->fail=root;
      q.push(root->next[i]);
    } else root->next[i]=root;
  while (!q.empty()) {
    trie *now=q.front(); q.pop();
    for (int i=0;i<4;i++) {
      trie *u=now->next[i];
      if (u) {
        q.push(u);
        trie *v=now->fail;
        while (v->next[i]==NULL)
          v=v->fail;
        u->fail=v->next[i];
      }
    }
    if (now->fail->isend) now->isend=1;
  }
}

int dp[1010][1010];

trie* go(trie *now,char ch) {
  ch -= '0';
  trie *ans = now;
  while (ans -> next[ch] == NULL)
    ans = ans -> fail;
  return ans -> next[ch];
}

int main() {
  int ii=1;
  for (;;) {
    int n;
    scanf("%d",&n);
    if (n==0) break;
    root=head=pool;
    memset(dp,0x7f,sizeof(dp));
    memset(pool,0,sizeof(pool));

    static char buf[30];
    for (int i=0;i<n;i++) {
      scanf("%s",buf);
      toInt(buf);
      insert(buf);
    }
    buildFaliure();

    static char word[1010];
    scanf("%s",word);
    toInt(word);
    dp[0][0]=0;
    n=head-pool;
    int len;
    for (len=0;word[len];len++) {
      for (int j=0;j<n;j++)
        if (dp[j][len]<=len) {
          for (char ch='0';ch<='3';ch++) {
            trie *tmp=go(pool+j,ch);
            if (tmp->isend) continue;
            int next=tmp-pool;
            int delta=0; if (ch!=word[len]) delta++;
            if (dp[next][len+1] > dp[j][len] + delta)
              dp[next][len+1] = dp[j][len] + delta;
          }
        }
    }
    int ans=2000000000;
    for (int j=0;j<n;j++)
      if (dp[j][len]<ans) ans=dp[j][len];
    if (ans>len) ans=-1;
    printf("Case %d: %d\n",ii++,ans);
  }
  return 0;
}
