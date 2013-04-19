#include <cstdio>
using namespace std ;
#define maxn 509
#define max(a,b) a>b?a:b 

int t,n;
int dp[maxn][maxn] ;

void DP_run () {
    dp[2][2] = 1 ;
    for ( int i = 0 ; i <= 500 ; ++i ) {
        dp[i][i] = dp[i][i-1] = 1 ;   // i itself
        for ( int j = 0 ; j <= 500 ; ++j ) {
            if ( i == 0 ) dp[i][j] = 1 ;
            else if ( i < j ) dp[i][j] = 0 ;
            else {
                dp[i][j] = 0 ;
                for ( int k = max(2,j) ; k <= i ; ++k ) {
                    dp[i][j] = (dp[i][j]+dp[i-k][k])%1000007 ;
                }
            }
        }
    }
}
int main () {

    scanf ( "%d" , &t ) ;
    DP_run() ;
    while ( t-- ) {
        scanf ( "%d" , &n ) ;
        printf ( "%d\n" , dp[n][2] ) ;
    }
    //system ( "pause" ) ;
    return 0 ;
}                                 
