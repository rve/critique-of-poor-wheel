#include<iostream>
#include<bitset>
using namespace std;
const int n = 4;
const int maxn = (int) (1e5 + 5);
int main()
{
    int sum =0;
    int nn;
    int a[maxn];
    scanf("%d", &nn);
    for (int i=1; i<=nn; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i < (1 << nn); i++)
    {
        bitset<n> bit(i);
        int s = 1;

        for(int j = bit.size() - 1; j >= 0; j--)
        {
            cout<<bit[j];
            if (bit[j]) {
                s *= a[i];

            }

        }
        cout<<endl;
        sum += s;
    }
    cout<<sum<<endl;
    return 0;
}
