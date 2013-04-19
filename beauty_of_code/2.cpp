#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdio>
#define MAXN 1001
using namespace std;
char text[4002],pat[4002];
int next[4002];
void get_next(char *s)
{

    int i=0,j=-1,len=strlen(s);
    next[0]=-1;
    while(i<len)
    {
        if(j==-1||s[i]==s[j])
        {
            i++;
            j++;
            next[i]=j;
        }
        else
            j=next[j];
    }
}
int kmp()
{
    int len1=strlen(text),len2=strlen(pat);
    int i=0,j=0;
    while(i<len1&&j<len2)
    {
        if(text[i]==pat[j]||j==-1) 
        {
            i++,j++;
        }
        else
            j=next[j];
    }
    if(j>=len2) return i-len2;
    else return -1;
}
int main()
{
    int len,i,j;
    while(gets(pat))
    {
        gets(text);
        get_next(pat);
        printf("%d\n",kmp());
    }
    return 0;
}
