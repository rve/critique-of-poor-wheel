#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
using namespace std;
int main()
{
    int n, m, k;
    cin>>n>>m>>k;
    map<int, int> mp;
    for (int i=0; i<n; i++)
    {
        scanf("%d", &k);
        mp[k] ++;
    }
    for (int j=0; j<m; j++)
    {
        scanf("%d", &k);
        mp[k] --;
    }
    k = 0;
    for(map<int, int> :: reverse_iterator rit = mp.rbegin(); rit != mp.rend(); rit++)
    {
        k += rit->second;
        if (k > 0)
        {
            puts("YES"); return 0;
        }

    }
    puts("NO"); return 0;
}
