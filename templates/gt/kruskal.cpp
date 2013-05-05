#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
 
const int MAXN = 100;
const int MAXM = 10000;
const int EXP = 10;
const int INF = 1000000000;
 
int nn,mm;
 
struct EDGE{
  int f;
  int t;
  int v;
}pool[MAXM+EXP];
 
bool cmp(EDGE a, EDGE b){
  return a.v < b.v;
}
 
int fa[MAXN+EXP];
int find(int x){
  int r = x;
  while(r != fa[r]) r = fa[r];
  while(x != r){
    int tmp = fa[x];
    fa[x] = r;
    x = tmp;
  }
  return r;
}
 
void uni(int aa, int bb){
  int xx = find(aa);
  int yy = find(bb);
  if(xx != yy) fa[yy] = xx;
}
 
int sum; 
 
void Kruskal(){
  sum = 0; 
  sort(pool, pool+mm, cmp); 
  for(int i = 1; i <= nn; i++) fa[i] = i;
  for(int i = 0; i < mm; i++){
    int aa = find(pool[i].f);
    int bb = find(pool[i].t);
    if(aa == bb) continue;
    sum += pool[i].v;  
    uni(aa, bb);
  }
}
 
 
int main(){
  int cas;    scanf("%d", &cas);
  while(cas--){
    scanf("%d%d", &nn, &mm);
    for(int i = 0; i < mm; i++) 
      scanf("%d%d%d", &pool[i].f, &pool[i].t, &pool[i].v);
    Kruskal();
    printf("%d\n",sum);
  }
  return 0;
}
