#include<stdio.h>
int cal(int a,int b)
{
    __asm
    {
        mov eax,a;
        mov ebx,b;
        add eax,ebx;
    }
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d\n",cal(a,b));
}
