#include<iostream>
#include<string>
#include<cmath>
#include<cstring>
#include<cstdio>
#define MAXN 70
#define INF 0x3f3f3f3f
using namespace std;
int main()
{
    int T;
    scanf("%d", &T);
    for (int s=0; s<T; s++)
    {
        int n;
        scanf("%d", &n);
        double x[MAXN];
        double y[MAXN];
        double tmp=0;
        double maxx, minx;
        for (int i=0; i<n; i++)
        {
            scanf("%lf %lf", &x[i], &y[i]);
            if (x[i] > maxx) maxx = x[i];
            if (x[i] < minx) minx = x[i];
            tmp += x[i];
        }
        tmp /= n;
        double a = floor (tmp), b= ceil(n);
        double mid;
        for (int i=0; i<= (int) (1e7); i++)
        {

        }
        while ( (maxx - minx) > 1e-7)
        {
            mid = (maxx + minx) /2;
            double m1,m2,m3;
            for (int i=0; i<n; i++)
            {
                double t1= (x[i] - mid) * (x[i] -mid) + y[i] * y[i];
                double t2= (x[i] - maxx) * (x[i] -maxx) + y[i] * y[i];
                double t3= (x[i] - minx) * (x[i] -mid) + y[i] * y[i];
                if (t1 > m1) m1 = t1;
                if (t2 > m2) m2 = t2;
                if (t3 > m3) m3 = t3;
            }

        }
        
    }
}
