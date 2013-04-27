#include <iostream>
#include <cstdio>
 
using namespace std;
 
const int MAXN = 1000;
const int MAXM = 2000;
const int EXP = 10;
const int INF = 1000000000;
 
int mm,nn;
 
int vf[MAXM+EXP],vt[MAXM+EXP],vc[MAXM+EXP];     //记录边
 
int dist[MAXN+EXP];
 
void init(){
  scanf("%d%d",&nn,&mm); 
  for(int i = 0; i < mm; i++){ 
    scanf("%d%d%d",vf+i,vt+i,vc+i);
  }
}
 
void Bellman_Ford(int s){
  for(int i = 1; i <= nn; i++)   dist[i] = INF;
  dist[s]=0;
  for(int i = 0; i < nn-1; i++){   
    for(int i = 0; i < mm; i++){
      if(dist[vf[i]] + vc[i] < dist[vt[i]]){
        dist[vt[i]] = dist[vf[i]] + vc[i];
      }
      if(dist[vt[i]] + vc[i] < dist[vf[i]]){
        dist[vf[i]] = dist[vt[i]] + vc[i];
      }
    }
  }
}
 
int main(){
  init();
  Bellman_Ford(1);
  printf("%d\n",dist[nn]);
  return 0;
}
