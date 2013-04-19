#include<iostream>
#include<cstring>
#include<cstdio>
#define MAXN 100100
using namespace std;
int c[MAXN]; 
int max_val;
int read(int idx)
{
    int sum = 0;
    while (idx > 0)
    {
        sum += c[idx];
        idx -= idx & (-idx);
    }
    return sum;
}
void update(int idx, int val)
{
    while (idx <= max_val)
    {
        c[idx] += val;
        idx += idx & -idx;
    }
}
int main()
{
    int n;
    while (scanf("%d", &n) != EOF, n != 0)
    {
        memset(c, 0, sizeof(c));
        max_val = n;
        for (int i=0; i<n; i++)
        {

            int a, b;
            scanf("%d%d", &a, &b);
            
            update(a, 1);
            update(b+1, -1);

        }
        for (int i=1; i<n; i++)
        {
            printf("%d ", read(i));
        }
        printf ("%d\n", read(n));
    }
}
