#include <iostream>
using namespace std;

int main()
{
    int weight1, weight2, weight3, rate1, rate2, rate3, rate4;
    int size, add, cost;
    int t = 0;

    while ( cin >> weight1 >> rate1 >> weight2 >> rate2 >> weight3 >> rate3 >> rate4 ) {
        t++;
        cout << "Set number " << t << ":"<<endl;
        while ( !0 ) {
            cin >> size;
            if ( size == 0 )
                break;

            add = 0;
            if ( size <= weight1 ) {
                cost = rate1 * size;
                if ( ( weight1 + 1 ) * rate2 < cost ) {
                    add = weight1 + 1 - size;
                    cost = ( weight1 + 1 ) * rate2;
                }
                if ( ( weight2 + 1 ) * rate3 < cost ) {
                    add = weight2 + 1 - size;
                    cost = ( weight2 + 1 ) * rate3;
                }
                if ( ( weight3 + 1 ) * rate4 < cost ) {
                    add = weight3 + 1 - size;
                    cost = ( weight3 + 1 ) * rate4;
                }
            }
            else if ( size > weight1 && size <= weight2 ) {
                cost = rate2 * size;
                if ( ( weight2 + 1 ) * rate3 < cost ) {
                    add = weight2 + 1 - size;
                    cost = ( weight2 + 1 ) * rate3;
                }
                if ( ( weight3 + 1 ) * rate4 < cost ) {
                    add = weight3 + 1 - size;
                    cost = ( weight3 + 1 ) * rate4;
                }
            }
            else if ( size > weight2 && size <= weight3 ) {
                cost = rate3 * size;
                if ( ( weight3 + 1 ) * rate4 < cost ) {
                    add = weight3 + 1 - size;
                    cost = ( weight3 + 1 ) * rate4;
                }
            }
            else
                cost = rate4 * size;

            cout << "Weight (" << size << ") has best price $" << cost << " (add " << add << " pounds)"<< endl; 
        }

        cout << endl;

    }

    return 0;

}                                 
