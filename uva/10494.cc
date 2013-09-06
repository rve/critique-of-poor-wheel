#define TEST
#include<stdio.h>
#include<climits>
#include<algorithm>
#include<vector>
#include<iostream>
#include<assert.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<map>
#define EPS 0.0000001
#define M 12100
using namespace  std;
struct bn {
    int d[M];
    int len;
    bn() {
        len=0; memset(d, 0, sizeof(d));
    }
};
long long div(bn &a, int b, bn &c) {
    long long r=0;
    for (int i=M-1; i>=0; i--)
    {
        r = r*10 + a.d[i];
        c.d[i] = r / b;
        r %= b;
    }
    return r;
}
int gt(bn a, bn b) {
    for (int i=M-1; i>=0; i--) {
        if (a.d[i] > b.d[i]) return 1;
        else if (a.d[i] < b.d[i]) return -1;
    }
    return 0;
}
void add(bn &a, bn &b, bn &c) {
    for (int i=0; i<M; i++) {
        c.d[i] = a.d[i] + b.d[i];
    }
    for (int i=0; i<M; i++) {
        if (c.d[i] >= 10) {
            c.d[i+1] ++;
            c.d[i] -= 10;
        }
    }
    int i;
    for (i=M-1; i>=0; i--) {
        if  (c.d[i] != 0) break;
    }
    c.len = i;
}
void sub(bn &a, bn &b, bn &c) {
    for (int i=0; i<M; i++) {
        c.d[i] = a.d[i] - b.d[i];
    }
    for (int i=0; i<M; i++) {
        if (c.d[i] <0) {
            c.d[i+1] --;
            c.d[i] += 10;
        }
    }
    int i;
    for (i=M-1; i>=0; i--) {
        if (c.d[i] != 0) break;
    }
    c.len = i;
}
void mul(bn &a, bn &b, bn &c) {
    for (int i=0; i<M; i++) {
        for (int j=0; j<M; j++)
        {
            c.d[i+j] += a.d[i] * b.d[j];
        }
    }
    for (int i=0; i<M; i++) {
        c.d[i+1] += c.d[i] / 10;
        c.d[i] = c.d[i] % 10;
    }
}
void trans(string s, bn &a) {
    int acc=0;
    for (int i=s.size()-1; i>=0; i--) {
        a.d[acc++] = s[i] - '0';
    }
    a.len=s.size()-1;
}
void trans(int s, bn &a) {
    char buf[M+10];
    sprintf(buf, "%d", s);
    string str(buf);
    trans(str, a);
}
void print(bn &a) {
    int i;
    for (i=M-1; i>=0; i--) {
        if  (a.d[i] != 0) break;
    }
    a.len = i;
    if (a.len == -1) {
        printf("0\n"); return;
    }
    for (int i=a.len; i>=0; i--) {
        printf("%d", a.d[i]);
    }
    printf("\n");
}
const string MAXINT="2147483647";
int main() {
#ifdef TEST
    freopen("data.in", "r", stdin);
#endif
    string sa;
    int nb;
    char op;
    while(cin>>sa>>op>>nb) {
        bn a, b, c;
        trans(sa, a);
        if (op == '+') {
            trans(nb, b);
            add(a, b, c );
            print(c);
        }
        else if (op == '-') {
            trans(nb, b);
            sub(a, b, c);
            print(c);
            
        }
        else if (op == '*') {
            trans(nb, b);
            mul(a, b, c);
            print(c);
        }
        else if (op == '/') {
            div(a, nb, c);
            print(c);
        }
        else if (op == '%') {
            long long  r = div(a, nb, c);
            cout<<r<<endl;
        }

    }
}
