#include <iostream>
#include <string>
#include<cstring>
using namespace std;

int arr[10000];
int size = 0;

int stringToInt(string str)
{
    int size = str.size();
    int power = 1;
    int ans = 0;
    for(int i=str.size()-1; i>=0; i--)
    {
        ans += ((str[i]-48) * power);
        power *= 10;
    }
    return ans;
}

string intToString(int num)
{
    if(num == 0)
        return "0";
    string ans = "";
    int tmp = num;
    while(1)
    {
        int c = tmp % 10;
        tmp /= 10;
        ans += (char)(c + 48);
        if(tmp == 0)
            break;
    }
    string res = "";
    for(int i=ans.size()-1; i>=0; i--)
        res += ans[i];
    return res;
}

bool deter(int n)
{
    for(int i=0; i<size; i++)
        if(n == arr[i])
            return true;
    return false;
}

void solve(int n)
{
    int nn = n * n;

    int count = 0;
    arr[size++] = n;
    while(1)
    {    
        string str = intToString(nn);

        while(str.size() < 8)
            str = "0" + str;

        str = str.substr(2, 4);

        int newNumber = stringToInt(str);

        if(deter(newNumber))
        {
            cout << count+1 << endl;
            return ;
        }
        else
        {
            arr[size++] = newNumber;
            count++;
            nn = newNumber * newNumber;
        }

    }
}

int main()
{
    string n;

    while(cin >> n, n != "0")
    {
        size = 0;    
        int m = stringToInt(n);    
        solve(m);
    } 

    return 0;
}                                 
