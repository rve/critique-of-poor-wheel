#include<iostream>
#include<cstring>
#include<cstdio>
#define MAXN 101000
using namespace  std;
int main() 
{
    int t;
    scanf("%d", &t);
    for (int k=0; k<t; k++)
    {
        int n, a, b;
        int flag = 100;
        if (n == 0) flag  = 0;
        scanf("%d %d %d", &n, &a, &b);
        if ( b >= 2 * a) flag = -1;
        else if (  b <= a) flag = 1;
        else  if ( n <= b /2) flag = -1;
        else
        {

            int x = b / 2;
            int carry = 0;
            if ( n - x > a  &&  b%2 == 1) carry = 1;
            b = x + carry;// - n  * (1,2) 
            a = min (n - x, a);
            if ( b == a ) flag = 0;
            else if ( b > a) flag = -1;
            else if ( b < a ) flag = 1;

        }

        printf("Case #%d: ", k+1);
        printf("%d\n", flag);
    }
}
