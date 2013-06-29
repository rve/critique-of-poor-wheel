#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int queen[100];
int num =0;
bool check(int n) {
    for (int i=0; i<n; i++) {
        if (queen[i] == queen[n] || abs(queen[i] - queen[n]) == n-i)
            return 0;
    }
    return 1;
}
void dfs(int n) {
    if (n == 8) {
        num++;
        if (num<=3) {
            for (int i=0; i<8; i++) {
                printf("(%d,%d)",i, queen[i]);
            }
            printf("\n");
        }
        return;
    }
    for (int i=0; i<8; i++) {
        queen[n] =i;
        if (check(n)) {
            dfs(n+1);
        }
    }
}
int main() {
    dfs(0);
    cout<<num<<endl;

}
