/*
ID: jiongrr1
PROG: contact
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<string>
#include<set>
#include<iterator>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<map>
#define INF 0x3f3f3f3f
#define MAXN 10010
using namespace std;
bool cmp(const pair<int, string>& a, const pair<int, string>& b)
{
    if (a.first > b.first) return true;
    else if (a.first < b.first) return false;
    else 
    {
        if (a.second.size() > b.second.size()) return false;
        else if (a.second.size() < b.second.size()) return true;
        else
            return a.second < b.second;
    }
}
int main()
{
    vector<pair<int , string> > v;
    map<string, int> m;

    freopen("contact.in", "r", stdin);
    freopen("contact.out", "w", stdout);
    int a, b, n;
    string str = "";
    string line = "";
    scanf("%d %d %d", &a, &b, &n);
    while( getline(cin, line))
    {
        str += line;
    }
    m.clear();
    v.clear();

    for(int i = a; i<=b; i++)
        for(int j = 0; j + i <= str.size(); j++)
        {
            m[str.substr(j, i)] ++;
        }

    map<string, int> ::iterator mi;
    for(mi = m.begin(); mi != m.end(); mi++)
    {
        v.push_back(make_pair(mi->second, mi->first));
    }
    sort(v.begin(), v.end(), cmp);
    int acc = 0;
    for(int i=0; i<v.size() && acc != n; i++, acc++)
    {
        printf("%d\n", v[i].first);
        if (v[i+1].first == v[i].first)
        {
            int j;
            for(j=1; i + j < v.size() && v[i+j].first == v[i].first; j++)
            {
                printf("%s", v[i + j - 1].second.c_str());
                if (j % 6 == 0)
                    printf("\n");
                else
                    printf(" ");


            }
            printf("%s\n", v[i + j - 1].second.c_str());
            i += j - 1;
        }
        else
        {
            printf("%s\n", v[i].second.c_str());
        }
    }


}
