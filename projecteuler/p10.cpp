#include <iostream>
using namespace std;
 
bool isPrime(int nr)
{
    for (int d = 2; (d * d) < (nr + 1); ++d){
        if (!(nr % d)){
            return false;
        }
     }
    return true;
}
 
int main (int argc, char * const argv[])
{
    long long ans=0;
    const int inf = 2e6;
    cout<<inf<<endl;
    for (int i = 2; i < inf; ++i){
        if (isPrime(i)){
            ans += i;
            }
        }
    cout<<ans<<endl;
}
