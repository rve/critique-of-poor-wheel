#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 302
#define INF 0x3f3f3f3f
using namespace std;
int f[MAXN][MAXN];
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    int d[MAXN];
    int i=0;
    scanf("%d", &a[i]);
  for (int i=1; i<2*n-1; i++) {
    scanf("%d", &d[i++]);
    d[i] = d[i-1];
  }
  scanf("%d", &d[2*n-1]);
  memset(f, 0, sizeof(f));
  int j;
  int temp;
  for (int step-1; step<n; step++)
    for (int i=0; i<n*2; i++)
      j = i + step;
  if (j >= n*2 ) break;
  for (int k=i; k<j; k++) {
    temp = ans[i][k] + ans[k+1][j] + a[i]*a[k+1]*a[j+1];
  if (ans[i][j] < temp)
    ans[i][j] = temp;
      }
    }
}
