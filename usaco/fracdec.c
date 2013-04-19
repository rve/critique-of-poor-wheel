/*
ID: jiongrr1
LANG: C
TASK: fracdec
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAXN 100010
int lastrem[MAXN];
int n, d;
char dec[MAXN];
char buf[MAXN];
int main()
{
    freopen("fracdec.in", "r", stdin);
    freopen("fracdec.out", "w", stdout);
    scanf("%d %d", &n, &d);
    sprintf(buf, "%d.", n / d);
    int rem = n % d;
    n = rem;
    int i = 0;
    memset(lastrem, -1, sizeof(lastrem));
    do
    {
        if (rem == 0)
        {
            if (i == 0)
            {
                sprintf(buf + strlen(buf), "0");
            }
            else
            {
                sprintf(buf + strlen(buf), "%s", dec);
            }
            break;
        }
        else if (lastrem[rem] != -1)
        {
            sprintf(buf + strlen(buf), "%.*s(%s)", lastrem[rem], dec, dec + lastrem[rem]);
            break;
        }

        lastrem[rem] = i;
        n = n * 10;
        dec[i] = n / d + '0';
        rem = n % d;
        n = rem;
    } while(i++ >= 0);

    for (i = 0; i < strlen(buf); i += 76)
    {
        printf("%.76s\n", buf + i);
    }

}
