#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
struct date {
    int y,m,d;
};
int m[]={0, 31,28,31,30,31,30,31,31,30,31,30,31};
int leap(int n) {
    if ((n % 4 == 0 && n % 100) || (n%400 == 0)) {
        return 1;
    }
    else return 0;
}
int calc(date& a) {
    int sum =0;
    for (int i=1899; i<a.y; i++) {
        sum += 365 + leap(i);
    }
    for (int i=1; i<a.m; i++) {
        sum += m[i];
        if (i == 2 ) sum += leap(a.y);
    }
    sum += a.d;
    return sum;
}
int main()
{
    date a, b;
    scanf("%d:%d:%d", &a.y, &a.m, &a.d);
    scanf("%d:%d:%d", &b.y, &b.m, &b.d);
    cout<<abs(calc(a) - calc(b))<<endl;
    return 0;
}
