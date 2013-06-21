#define LOCAL
#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN= 1100;
int main()
{
#ifdef LOCAL 
    freopen("data.in","r",stdin);  
#endif
    int T;
    scanf("%d", &T);
    while(T--) {
        int s[MAXN];
        int n, f, b;
        scanf("%d%d%d", &n, &f, &b);
        for (int i=0; i<n; i++) {
            int t;
            scanf("%d%d", &s[i], &t);
            if (t == 0) {
                s[i] = s[i] + f;
            }
            else {
                s[i] = 3*f - s[i];
            }
        }
        int ans1 = b/n * 2 * f;
        sort(s, s+n);
        int rem = b % n;
        if (rem == 0) {
            rem  = n;
            ans1 -= f * 2;
        }
        int ans2 = 0;
        for (int i=0; i<rem; i++) {
            ans2 = max(ans2,s[i]);
        }
        cout<<ans1+ans2<<endl;
    }

}                                 
