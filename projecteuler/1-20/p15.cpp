#include<iostream>
#include<cstring>
using namespace std;
long long a[25][25];
int main() {
    memset(a, 0, sizeof(a));
    a[1][0] = 1;
    for (int i=1; i<=21; i++) {
        for (int j=1; j<=21; j++) {
            a[i][j] = a[i][j-1] + a[i-1][j];
        }
    }
    cout<<a[3][3]<<" "<<a[21][21];
}
