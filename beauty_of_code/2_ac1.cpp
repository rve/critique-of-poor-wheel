#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 0;i < T; ++i)
    {
        int n,ca,cb;
        scanf("%d%d%d",&n,&ca,&cb);
        int ans = -2;
        if(ca + cb < n)
        {
             if(ca > cb)
             ans = 1;
             if(ca < cb)
             ans = -1;
             if(ca == cb)
             ans = 0;
        }
        if(n == 0)
        {
            ans = 0;
        }
        if(n == 1)
        {
            if(ca >= cb)
            ans = 1;
            else
            ans = -1;
        }
        if(n >= 2 && (ca + cb) >= n)
        {
            if(n%2 == 1)
            {
                int mid = (n+1) / 2;
                if((cb / (ca / mid +1 )<= (n - mid)))
                {
                    ans = 1;
                }
                else
                ans = -1;
            }
            else
            {
                int k1 = n /2;
                int k2 = k1 +1;
                if((cb / (ca / k2 +1 )<= (n - k2)))
                    ans = 1;
                else
                {
                    if((cb / (ca / k1 +1 )<= (n - k1)))
                    ans = 0;
                    else
                    ans = -1;
                }
            }
        }
        printf("Case #%d: %d\n",i+1,ans);
    }
    return 0;
}
