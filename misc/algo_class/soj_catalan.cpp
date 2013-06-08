#include<iostream>
#include<cstdio>
using namespace std;

long long h[2200];
void Catalan(long long n)
{
    h[0] = h[1] = 1;        //h(0)和h(1)
    for(long long i = 2; i <= n; i++)    //依次计算h(2),h(3)...h(n)
    {
        h[i] = 0;
        for(long long j = 0; j < i; j++) //根据递归式计算 h(i)= h(0)*h(i-1)+h(1)*h(i-2) + ... + h(i-1)h(0)
        {

            h[i] += ((h[j]  ) * (h[i-1-j]) );
            if (h[i] >= 1000000007) {
                h[i] %= 1000000007;
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    Catalan(2200);

    while(t--) {
        int n;
        cin>>n;
        cout<<h[n/2]<<endl;
    }
}
