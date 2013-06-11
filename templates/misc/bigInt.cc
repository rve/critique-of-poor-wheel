#include<iostream>
using namespace std;
#define NUM 100
void add(int a[], int b[], int c[]) {
    for (int i=0; i<NUM; i++) {
        c[i] = a[i] + b[i];
    }
    for (int i=0; i<NUM; i++) {
        if (c[i] >= 10) {
            c[i+1] += c[i]/10;
            c[i] %= 10;
        }
    }
}
void print(int c[]) {
    int i = NUM -1;
    while(c[i] == 0) {
        i--;
    }
    while(i>=0) cout<<c[i--];
}
bool lt(int a[], int b[]) {
    int i = NUM -1;
    for (; i>=0; i--) {
        if (a[i] != b[i]) {
            return a[i] > b[i];
        }
    }
    return 0;
}
void sub(int a[], int b[], int c[]) {
    for (int i=0; i<NUM; i++) {
        c[i] = a[i] - b[i];
    }
    for (int i=0; i<NUM; i++) {
        if (c[i] < 0) {
            c[i+1] --;
            c[i] += 10;
        }
    }
}
int main() {
    int a[NUM], b[NUM], c[NUM];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    a[0] = b[0] = 3;
    a[1] = b[1] = 2;
    a[2] = b[2] = 1;
    add(a, b, c);
    print(c);

}
