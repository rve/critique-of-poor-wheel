#include<iostream>
#include<string>
using namespace std;

int failure[100];
void mp(string& t, string& p)
{
    if (p.size() > t.size()) return;
    for (int i=1, j=failure[0]=-1; i<p.size(); ++i)
    {
        while (j >=0 && p[j+1] != p[i])
            j = failure[j];
        if (p[j+1] == p[i]) j++;
        failure[i] = j;
    }

    for (int i=0, j=-1; i<t.size(); ++i)
    {
        while (j >= 0 && p[j+1] != t[i])
            j = failure[j];
        if (p[j+1] == t[i]) j++;
        if (j == p.size() -1)
        {
            cout << "P occured at " << i - p.size() + 1;
            j = failure[j];
        }
    }
}
int main()
{
    string t = "AABZABZABCZ",
           p = "ABZABC";
    mp(t, p);
}
