#include <iostream>
#include <cstdio>
using namespace std;
 
const int MAXN = 100;
const int EXP = 10;
const int INF = 1000000000;
 
int nn;
int map[MAXN+EXP][MAXN+EXP];
 
int sum; 
bool inSet[MAXN+EXP];
int dist[MAXN+EXP];  
 
void Prim(){
  sum = 0;    
  for(int i = 1; i <= nn; i++) inSet[i] = 0, dist[i] = INF; 
  dist[1] = 0;  
  for(int i = 0; i < nn; i++){ 
    int min = INF, idx = 0;
    for(int j = 1; j <= nn; j++)
      if(!inSet[j] && dist[j] < min)
        min = dist[j], idx = j;
    inSet[idx] = 1; 
    sum += min;   
    for(int j = 1; j <= nn; j++)
      if(!inSet[j] && dist[j] > map[idx][j])
        dist[j] = map[idx][j];
  }
}
 
int main(){ 
  while(scanf("%d\n",&nn) == 1 && nn){
    for(int i = 1; i <= nn; i++) 
      for(int j = 1; j <= nn; j++)
        scanf("%d",&map[i][j]);
    Prim();
    printf("%d\n",sum);
  }
  return 0;
}
