#include<iostream>
#include<string>
#define MAXN 10010
#define INF 0x3f3f3f3f
using namespace std;
int fail[100];
void kmp(string& t, string& p)
{
    //pre
    if (p.size() > t.size())
        return;
    for(int i = 1, j = fail[0] = -1; i < p.size(); ++i)
    {
        while (j >= 0 && p[j+1] != p[i])
            j = fail[j];
        if (p[j+1] == p[i])
            j++;
        fail[i] = j;
    }


    //mp
    for(int i = 0, j = -1; i < t.size(); ++i)
    {
        while(j >= 0 && p[j+1] != t[i])
            j = fail[j];

        if (p[j+1] == t[i])
            j++;
        if (j == p.size() - 1)
        {
            cout << "Pattern found : " << i - p.size() + 1 << endl;
            j = fail[j];
        }

    }
}
int main()
{
    string s, p;
    cin >> s >> p;
    kmp(s, p);
    

}
