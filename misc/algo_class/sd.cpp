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
 
bool inQ[MAXN+EXP];
int dist[MAXN+EXP];
 
void spfa(int s){ 
  for(int i = 0; i <= nn; i++){
    inQ[i] = 0;             
    dist[i] = INF;
  }
  queue<int> Q; Q.push(s); 
  inQ[s] = 1; dist[s] = 0;
  while(Q.size()){
    int now = Q.front(); Q.pop();
    inQ[now] = 0;
    for(EDGE* tmp = lnk[now].nxt; tmp; tmp = tmp->nxt){
      if(dist[now] + tmp->d < dist[tmp->n]){
        dist[tmp->n] = dist[now] + tmp->d;
        if(!inQ[tmp->n]) { 
          Q.push(tmp->n);
          inQ[tmp->n] = 1;
        }
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
    spfa(1);    
    //cout<<dist[?]
  }
  return 0;
}
