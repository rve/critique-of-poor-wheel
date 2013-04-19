#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 10010
#define INF 0x3f3f3f3f
using namespace std;
int main() {
  int m, n;
  scanf("%d %d", &m, &n);
  int best = -1;
  for (int i=m; i<=n; i++)
    {
      int d = i, acc = 1;
      while (d != 1) {
        if ( d % 2 == 1) d = 3 * d + 1;
        else d /= 2;
        acc++;
      }
      if (acc > best) best = acc;
    }
  printf("%d\n", best);
}
