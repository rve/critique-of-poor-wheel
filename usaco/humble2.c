/*
ID: jiongrr1
LANG: C
TASK: humble
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#define INF 0x7fffffff
#define MAXPRIME 100
#define MAXN 100000
long  hum[MAXN];
int prime[MAXPRIME];
int nprime, nhum = 0;
int nth;
int pin[MAXPRIME];
int main()
{
    freopen("humble.in", "r",stdin);
    freopen("humble.out", "w", stdout);
    scanf("%d %d", &nprime, &nth);
    int i, j;
    for(i=0; i<nprime; i++)
        scanf("%d", &prime[i]);
    hum[nhum++] = 1;
    int minhum, minid;
    memset(pin, 0, sizeof(pin));
    while(nhum < nth + 1)
    {
        minhum = INF;
        minid = -1;
        for(j=0; j<nprime; j++)
        {
            while((double)prime[j] * hum[pin[j]] <= hum[nhum-1])
                pin[j]++;

            if((double)prime[j] * hum[pin[j]] < minhum)
            {
                minhum = prime[j] * hum[pin[j]];
                minid = j;
            }

        }

        pin[minid]++;
        hum[nhum++] = minhum;
    }

    printf("%d\n", hum[nth]);
    exit(0);

}
