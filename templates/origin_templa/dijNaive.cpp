#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
 
const int MAXN = 1000;
const int EXP = 10;
const int INF = 1000000000;
 
int nn;
int mm;
 
int map[MAXN][MAXN]; 
 
int dist[MAXN+EXP];  
bool inSet[MAXN+EXP]; 
 
void init(){          
  for(int i = 0; i <= nn; i++)
    for(int j = 0; j <= nn; j++)
      map[i][j] = INF;
}
 
void Dijk(int s){
  for(int i = 1; i <= nn; i++){
    dist[i] = INF; 
    inSet[i] = 0;
  }
  dist[s] = 0;
  for(int i = 1; i <= nn; i++){
    int min = INF, idx = 0;
    for(int j = 1; j <= nn; j++){
      if(!inSet[j] && dist[j] < min){
        min = dist[j];
        idx = j;
      }
    }
    inSet[idx] = 1;   
    for(int j = 1; j <= nn; j++){
      if(!inSet[j] && dist[idx] + map[idx][j] < dist[j])
        dist[j] = dist[idx] + map[idx][j];
    }
  }
}
 
int main(){
  int cas; scanf("%d", &cas);  
  while(cas--){
    scanf("%d%d", &nn, &mm);
    init();   
    for(int i = 1; i <= mm; i++){
      int aa,bb,dd; scanf("%d%d%d", &aa, &bb, &dd);
      if(map[aa][bb] > dd){
        map[aa][bb] = map[bb][aa] = dd;
      }
    }
    Dijk(1);
    cout<<dist[nn]<<endl;
  }
  return 0;
}
