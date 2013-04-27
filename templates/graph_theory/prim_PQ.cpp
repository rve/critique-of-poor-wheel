#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
 
const int MAXN = 100;
const int MAXM = 10000;
const int EXP = 10;
const int INF = 1000000000;
 
int nn,mm;
 
int edges;
struct EDGE{
  int n;
  int v;
  EDGE* nxt;
}pool[MAXM*2+EXP];
EDGE lnk[MAXN+EXP];
 
void addEdge(int _f, int _t, int _v){
  pool[edges].n = _t;
  pool[edges].v = _v;
  pool[edges].nxt = lnk[_f].nxt;
  lnk[_f].nxt = &pool[edges];
  edges++;
}
 
struct NODE{
  int n;
  int dst;
  NODE(int _n = 0, int _dst = 0){
    n = _n;
    dst = _dst;
  }
};
bool operator <(NODE aa, NODE bb){
  return aa.dst > bb.dst;
}
 
int sum;
bool inSet[MAXN+EXP];
int dist[MAXN+EXP]; 
 
void Prim_Prio(){
  sum = 0;  
  for(int i = 1; i <= nn; i++) inSet[i] = 0, dist[i] = INF;
  dist[1] = 0;
  priority_queue <NODE> Q; Q.push(NODE(1,0)); 
  while(Q.size()){
    NODE now = Q.top(); Q.pop();
    if(inSet[now.n]) continue;  
    inSet[now.n] = 1;
    sum += now.dst;  
    for(EDGE* tmp = lnk[now.n].nxt; tmp; tmp = tmp->nxt){
      if(!inSet[tmp->n] && tmp->v < dist[tmp->n]){
        dist[tmp->n] = tmp->v;
        Q.push(NODE(tmp->n,tmp->v));
      }
    }
 
  }
}
 
int main(){
  int cas; scanf("%d",&cas);
  while(cas--){
    scanf("%d%d", &nn, &mm);
    edges = 0;
    for(int i = 1; i <= nn; i++) lnk[i].nxt = 0;
    for(int i = 1; i <= mm; i++){
      int aa,bb,vv; scanf("%d%d%d", &aa, &bb, &vv);
      addEdge(aa, bb, vv);
    } 
    Prim_Prio();
    printf("%d\n",sum);
  }
  return 0;
}
