#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std ;

int f[100005] ;
int c[105] , num[105] ;
int n , V ;

void ZeroOnePack(int cost,int weight)
{
    for (int v=V ; v >= cost ; v --) 
        f[v]=max(f[v],f[v-cost]+weight) ;
}


void CompletePack(int cost,int weight)
{
    for (int v=cost ; v <= V ; v ++ ) 
        f[v]=max(f[v],f[v-cost]+weight) ;
}

void MultiplePack(int cost,int weight,int amount)
{
    if ( cost*amount>=V )
    {
        CompletePack(cost,weight) ;
        return ;
    }
    int k=1 ;
    while ( k<amount )
    {
        ZeroOnePack(k*cost,k*weight) ;
        amount=amount-k ;
        k=k*2 ;
    }
    ZeroOnePack(amount*cost,amount*weight) ;
}

int main() 
{
    while( cin >> V )
    {
        cin >> n;
        for(int i = 1 ; i <= n ; i ++)
        {
            cin >> num[i] >> c[i] ;
        }

        memset(f,0,sizeof(f)) ;
        for(int i = 1 ; i <= n ; i ++)
        {
            MultiplePack(c[i],c[i],num[i]) ;
        }

        cout << f[V] << endl;
    }
}
