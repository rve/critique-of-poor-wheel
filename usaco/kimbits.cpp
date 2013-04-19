/*
ID: jiongrr1
LANG: C++
TASK: kimbits
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#define MAXN 33
#define INF 0x3f3f3f3f
using namespace std;
int size[MAXN][MAXN];
string ans;
int n, l;
unsigned nth;
int upper;
void printbits(int n, int l, unsigned nth, int times);
int main()
{
    freopen("kimbits.in", "r", stdin);
    freopen("kimbits.out", "w", stdout);
    memset(size, 0, sizeof(size));
    size[1][1] = 1;
    scanf("%d %d %u", &n, &l, &nth);
    for(int i=1; i<=n; i++)
        size[i][0] = 1, size[i][i] = 1;
    for(int i=2; i<=n; i++)
        for(int j=1; j<i; j++)
            size[i][j] = size[i-1][j] + size[i-1][j-1];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            size[i][j] += size[i][j-1];
    upper = n;
    
    printbits(n, l, nth, 1);
    cout<<ans<<endl;
 
}
void printbits(int n, int l, unsigned nth, int times)
{
    if ( times == upper) 
    {
        if (nth == 1) ans += '0';
        else if (nth == 2) ans += '1';
        return;
    }
 
 
    if (size[n - 1][l] >= nth )
    {
        ans += '0';
        printbits(n-1, l, nth, times + 1);
    }
    else
    {
        ans += '1';
        printbits(n-1, l-1, nth - size[n-1][l], times + 1);
    }
}
