#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#define MAXN 100010
using namespace std;

int main()
{
    int t,sx, sy, ex, ey;
    cin>>t>>sx>>sy>>ex>>ey;
    string s;
    cin>>s;
    int i;
    for (i=0; i<t; i++)
    {
        char c = s[i];
        if (c=='N' && sy < ey) sy++;
        if (c=='S' && sy > ey) sy--;
        if (c=='E' && sx < ex) sx++;
        if (c=='W' && sx > ex) sx--;
        if (sx == ex && sy == ey) 
        {
            cout<<i+1<<endl; return 0;
        }
    }
    cout<<-1<<endl;
}
