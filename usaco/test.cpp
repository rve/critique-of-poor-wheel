#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    printf("%d\n", ("0" > "1") ? 1 : 0);
    printf("%d\n", ("1" > "0") ? 1 : 0);
    printf("%d\n", ("000" > "3") ? 1 : 0);
    printf("%d\n", ("b" >= "a") ? 1 : 0);
}
