#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
//const int inf = 13;
const int inf = 1000010;
int main() {
    int ans = 0;
    int id= 0;
    int mp[inf];
    memset(mp, 0, sizeof(mp));
    mp[1] = 0;
    for (int i=2; i<=inf; i++) {
        long long k = i;
        int cnt=0;
        while(k!=1) {
            if (k&1) {
                k = k*3+1;
            }
            else {
                k = k/2;
            }
            if (k < i) {
                cnt = mp[i] = mp[k] + cnt;
                break;
            }
            cnt++;
        }
        if (cnt > ans) {
            ans = cnt;
            id = i;
        }
    }
    cout<<ans<<" "<<id<<endl;
}
