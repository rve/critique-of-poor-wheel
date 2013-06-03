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
    int cnt = 0;
    for (int i = 2; i < 1e32; ++i){
        if (isPrime(i)){
            cnt ++;
            if (cnt == 10001){
                cout<<i<<endl;
                break;
            }
        }
    }
}
