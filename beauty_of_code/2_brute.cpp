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
        char s1[MAXN];
        char s2[MAXN];
        scanf("%s", s1);
        scanf("%s", s2);
        int best = 100000;
        for (int i=0; i<strlen(s1) - strlen(s2) + 1; i++)
        {
            int acc =0; 
            for (int j=0; j< strlen(s2); j++)
            {
                if (s1[i +j] != s2[j] )
                    acc ++;
                if (acc >= best ) break;
            }
            if ( acc < best) best = acc;
        }
        printf("Case #%d: ", k+1);
        printf("%d\n", best);
    }
}
