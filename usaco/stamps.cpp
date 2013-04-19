/*
ID: jiongrr1
LANG: C++
TASK: stamps
*/
#include <fstream>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int BIG = 202;
int stamps[BIG];
short ministamps[BIG * 10000];
int main()
{
    int k, n;
    freopen("stamps.in", "r", stdin);
    freopen("stamps.out", "w", stdout);
    scanf("%d %d", &k, &n);
    short biggest = -1;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &stamps[i]);
        if (biggest < stamps[i])
            biggest = stamps[i];
    }
    for(int i=0; i<biggest * k + 10; i++)
        ministamps[i] = BIG;
    ministamps[0] = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<BIG * biggest; j++)
        {
            if (ministamps[j] + 1 <= k)
            {
                if (ministamps[j + stamps[i]] > ministamps[j] + 1)
                    ministamps[j + stamps[i]] = ministamps[j] + 1;
            }
        }
    }

    int acc = 1;
    while( ministamps[acc] <= k)
        acc ++;

    printf("%d\n", acc - 1);


}
