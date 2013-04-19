#include<iostream>
#include<algorithm>
#include<cstdio>
#define MAXN 10010
#define INF 0x3f3f3f3f
using namespace std;
int a[4] = {0, 1, 1, 1}, b[4] = {1, 0, 0, 1};
int c[4];
int start[4] = {0, 1, 1, 1};
int init[4] = {1, 0, 1, 0};
int ans[4] = {0, 0, 0, 0};
int N;
int n,m;
int* matrix(int *a, int *b);
int* power(int *a, int n);
int solve();
int main()
{
    freopen("test.in", "r", stdin);
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        scanf("%d %d", &n, &m);
        power(a, n-1);
        cout<<c[0] + c[1]<<endl;

    }
}

int * matrix(int *a, int *b)
{
    c[0] = (a[0] * b[0] + a[1] * b[2]) % m;
    c[2] =( a[2] * b[0] + a[3] * b[2]) % m;
    c[1] =( a[0] * b[1] + a[1] * b[3]) % m;
    c[3] =( a[2] * b[1] + a[3] * b[3]) % m;

    return c;

}
int* power(int *a, int n)
{
    if (n == 0 || n == 1)
    {
        cout<<a[0] <<" "<<a[1]<<endl<<a[2]<<" "<<a[3]<<endl;
        //cout<<a[0]+a[1]<<endl;
        return matrix(a, b) ;
    }
    //ans[0] = a[0] * init[0] + a[1] * init[1];
    //ans[1] = a[2] * init[0] + a[3] * init[3];
    if (n % 2 == 1)
    {
        return matrix(power(matrix(a, a), n/2), start);
    }
    else
    {

        return matrix(power(matrix(a, a), n/2), b);

    }
}
