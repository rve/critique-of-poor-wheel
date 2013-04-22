#include <cstdio>
using namespace std ;
#define maxn 50009
#define max(a,b) a>b?a:b 

int t,n;
int a[maxn],c[maxn],mc[maxn] ;
int d[maxn],md[maxn] ;
int main () {

    scanf ( "%d" , &t ) ;
    while ( t-- ) {
        scanf ( "%d" , &n ) ;
        for ( int i = 0 ; i < n ; ++i ) {
            scanf ( "%d" , &a[i] ) ;
        }
        c[0] = a[0] ;
        for ( int i = 1 ; i < n ; ++i ) {
            if ( c[i-1] > 0 ) {
                c[i] = c[i-1] + a[i] ;
            }
            else c[i] = a[i] ;
        
        }
        mc[0] = c[0] ;
        for ( int i = 1 ; i < n ; ++i ) {
            mc[i] = max ( mc[i-1] , c[i] ) ;
        }
        d[n-1] = a[n-1] ;
        for ( int i = n-2 ; i >= 0 ; --i ) {
            if ( d[i+1] > 0 ) {
                d[i] = d[i+1] + a[i] ;
            }
            else d[i] = a[i] ;
            
        }
        md[n-1] = d[n-1] ;
        for ( int i = n-2 ; i >= 0 ; --i ) {
            md[i] = max ( md[i+1] , d[i] ) ;
        }
        int ans = -211199999 ;
        //for ( int i = 0 ; i < n ; ++i ) printf ( "%d  " , mc[i] ) ;
        //printf ( "\n" ) ;
        //for ( int i = 0 ; i < n ; ++i ) printf ( "%d  " , md[i] ) ;
        for ( int j = 0 ; j < n-1 ; ++j ) {
            ans = max ( ans , mc[j]+md[j+1] ) ;
        }
        printf ( "%d\n" , ans ) ;
    }
    //scanf ( "%d" , &t ) ;
    //system ( "pause" ) ;
    return 0 ;
}                                 
