#include <bits/stdc++.h>
using namespace std;

#define rep( i, n ) for( int i = 0; i < ( n ); i++ )
#define PI 3.14159265

typedef long long ll;

void InsertionSort( int a[], int n ) {
    for( int i = 0; i < n; i++ ) {
        int temp = a[ i ];
        int j    = i - 1;
        while( j >= 0 && a[ j ] > temp ) {
            a[ j + 1 ] = a[ j ];
            j--;
        }
        a[ j + 1 ] = temp;
        rep( k, n ) {
            if( k < n - 1 )
                cout << a[ k ] << " ";
            else
                cout << a[ k ] << endl;
        }
    }
}

//*******************
//エントリーポイント
//*******************
int main( void ) {
    int n;
    cin >> n;
    int a[ n ];
    rep( i, n ) cin >> a[ i ];
    InsertionSort( a, n );
    return 0;
}

