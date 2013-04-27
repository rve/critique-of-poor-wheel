#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
 
const int MAXN = 50000;
const int MAXM = 50000;
const int EXP = 10;
const int INF = 1000000000;
 
int edges;
struct EDGE{
  int n;
  int d;
  EDGE *nxt;
}pool[MAXM*2+EXP];
EDGE lnk[MAXN+EXP];
 
void addEdge (int _f, int _t, int _d){
  pool[edges].n = _t;
  pool[edges].d= _d;
  pool[edges].nxt = lnk[_f].nxt;
  lnk[_f].nxt = &pool[edges];
  edges++;
}
 
int nn;
int mm;
 
int dist[MAXN+EXP]; 
bool inSet[MAXN+EXP];
 
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
 
void Dijk_Prio(int s){
  for(int i = 1; i <= nn; i++){ 
    dist[i] = INF;
    inSet[i] = 0;
  }
  priority_queue <NODE> Q;
  dist[s] = 0;
  Q.push(NODE(s,dist[s]));    
  while(Q.size()){
    NODE now = Q.top(); Q.pop();
    if(inSet[now.n] == 1) continue;   
    inSet[now.n] = 1;     
    for(EDGE * tmp = lnk[now.n].nxt; tmp; tmp = tmp->nxt){  
      if(!inSet[tmp->n] && dist[now.n] + tmp->d < dist[tmp->n]){
        dist[tmp->n] = dist[now.n] + tmp->d;
        Q.push(NODE(tmp->n, dist[tmp->n]));
      }
    }
  }
}
 
int main(){
  int cas; scanf("%d", &cas); 
  while(cas--){
    edges = 0;
    scanf("%d%d", &nn, &mm);
    for(int i = 1; i <= nn; i++) lnk[i].nxt = 0;   
    for(int i = 1; i <= mm; i++){
      int aa,bb,dd; scanf("%d%d%d", &aa, &bb, &dd);
      addEdge(aa, bb, dd);
      addEdge(bb, aa, dd);
    }
    Dijk_Prio(1);
    //cout<<dist[?]
  }
  return 0;
}
