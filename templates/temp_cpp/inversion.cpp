#include <cstdio>

int a[500010];
int t[500010];
long long ans;

void merge(int a[],int sizea,int b[],int sizeb) {
    int nowa = 0;
    int nowb = 0;
    int s = 0;
    while (nowa < sizea && nowb < sizeb) {
        if (a[nowa]<=b[nowb])
            t[s++]=a[nowa++];
        else
        if (a[nowa]>b[nowb]) {
            t[s++] = b[nowb++];
            ans += sizea - nowa;
        }
    }
    while (nowa<sizea)
        t[s++]=a[nowa++];
    while (nowb<sizeb)
        t[s++]=b[nowb++];
}

void sort(int a[],int size) {
    if (size < 2)
        return;
    int lsize = size>>1;
    int rsize = size-lsize;
    sort(a, lsize);
    sort(a + lsize, rsize);
    merge(a, lsize, a+lsize, rsize);
    for (int i = 0; i < size; i++)
        a[i] = t[i];
}


int main() {
    while (1) {
        int n;
        scanf("%d",&n);
        if (!n)
            break;
        for (int i=0;i<n;i++)
            scanf("%d",a+i);
        ans = 0;
        sort(a,n);
        printf("%lld\n",ans);
    }
}
