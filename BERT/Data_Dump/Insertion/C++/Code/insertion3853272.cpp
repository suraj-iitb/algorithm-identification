#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+9, INF = 0x3f3f3f3f;
int dt[105];

void insertionSort( int n ) {
    for( int i = 1; i < n; ++i ) {
        int v = dt[i];
        int j = i - 1;
        while( j >= 0 && v < dt[j] ) {
            dt[j + 1] = dt[j];
            --j;
        }
        dt[j + 1] = v;
        for( int i = 0; i < n; ++i ) cout << dt[i] << ( i == n - 1 ? '\n' : ' ' );
    }
}

int main( void ) {
    ios::sync_with_stdio( false );
    int n;
    cin >> n;
    for( int i = 0; i < n; ++i ) cin >> dt[i];
    for( int i = 0; i < n; ++i ) cout << dt[i] << ( i == n - 1 ? '\n' : ' ' );
    insertionSort( n );
    return 0;
}

