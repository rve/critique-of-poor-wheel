#include <iostream>
#include <string>
using namespace std;

void quicksort(int l,int r,int *a)
{
    int i,j,x;
    if(l>=r) return;
    i=l;
    j=r;
    x=a[i];
    while(i!=j)
    {
        while(a[j]>x&&j>i) j--;
        if(i<j)
        {
            a[i]=a[j];
            i++;
        }
        while(a[i]<x&&j>i) i++;
        if(i<j)
        {
            a[j]=a[i];
            j--;
        }
    }
    a[i]=x;
    quicksort(l,j-1,a);
    quicksort(i+1,r,a);
}
int main()
{
    long int n,f,b,fi,bi;
    int t,time,i,j;
    int p,q;  
    // p times q person
    int a[1000];
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>f>>b;
        memset(a,-1,sizeof(a));
        for(j=0;j<n;j++)
        {
            cin>>fi>>bi;
            a[j]=fi;
            if(bi==1) a[j]=2*f-a[j];
        }
        quicksort(0,n-1,a);
        p=b/n;
        q=b%n;
        if(q==0) q=n-1;
        else{
            q--;
            p++;
        }
        a[q]+=p*2*f-f;
        cout<<a[q]<<endl;
    }
    return 1;
}
