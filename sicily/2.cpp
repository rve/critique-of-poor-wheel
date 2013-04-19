#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<map>
#define MAXN 10010
#define esp 0.01

#define INF 0x3f3f3f3f
using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    map<string, int> mp;
    string str[52];
    float ans[52];
    for(int i=0; i<n; i++)
    {
        cin>>str[i]>>ans[i];
    }

    string line;
    for(int i=0; i<m; i++)
    {
        //getline(cin, line);
        string lin[150]; 
        int acc = 0;
        string guard = "12323";
        cin>>lin[0]>>guard;
        acc++;

        while(guard == "+")
        {
            cin>>lin[acc];
            acc++;
            cin>>guard;

        }
        string sign = guard;
        int digit;
        cin>>digit;
        //cout<<"digit sign "<<digit<<" "<<sign<<endl;
        float sum =0; 
        for(int k=0; k<acc; k++)
        {
            for(int j=0; j<n; j++)
            {
                if (lin[k] == str[j])
                {
                    sum += ans[j];
                }
            }
        }
        int guess = digit;
        float dd =(sum - (float)guess);
        //printf("dd sum guess ");
        //printf("%f", dd);
        printf("Guess #%d was ", i+1);
        if (guard == "=" && ( -esp <= dd && dd < esp) )
            printf("correct.\n");
        else if ( guard == ">" && (dd > esp))
            printf("correct.\n");
        else if ( guard == "<" && dd  < -esp)
            printf("correct.\n");
        else if ( guard == ">=" && (dd > -esp))
            printf("correct.\n");
        else if ( guard == "<=" && (dd < esp))
            printf("correct.\n");
        else 
        printf("incorrect.\n");

    }


}
