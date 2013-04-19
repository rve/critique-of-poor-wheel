#include<stdio.h>
int cal(int a,int b)
{
    __asm__ ("movl %eax,(a)"
            "movl %ebx,(b)"
            "addl %eax,%ebx");
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d\n",cal(a,b));
}
