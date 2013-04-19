#include<iostream>
#include<cstdio>
using namespace std;

long long Catalan(long long n)
{
	if(n <= 1)
		return 1;

	long long *h = new long long [n+1]; //保存临时结果
	h[0] = h[1] = 1;        //h(0)和h(1)
	for(long long i = 2; i <= n; i++)    //依次计算h(2),h(3)...h(n)
	{
		h[i] = 0;
		for(long long j = 0; j < i; j++) //根据递归式计算 h(i)= h(0)*h(i-1)+h(1)*h(i-2) + ... + h(i-1)h(0)
      {

			h[i] += ((h[j] % 1000000007 ) * (h[i-1-j]) );
         if (h[i] > 1000000007)
             h[i] %= 1000000007;
         }
         
         

	}
	long long result = h[n]; //保存结果
	delete [] h;       //注意释放空间
	return result;
}
int main()
{
    freopen("data.out", "w", stdout);
    for(int i=1; i< 1005; i++)
    { 
        int n = Catalan(i);
        printf("%d,",n); 
    }
}
