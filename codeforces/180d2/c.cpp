#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<string>
using namespace std;
int main()
{
    string a, b;
    cin>>a>>b;
    int an =0, bn = 0;
    for (int i=0; i<a.size(); i++)
    {
        if (a[i] == '1')
        {
            an ++;
        }
    }
    an += (an % 2);
    for (int j=0; j<b.size(); j++)
    {
        if (b[j] == '1')
        {
            bn ++;
        }
    }
    if (an >= bn)   cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
}
