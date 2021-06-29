#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+9, INF = 0x3f3f3f3f;
int dt[105], ans = 0;

void selectionSort( int n ) {
    for( int i = 0; i < n; ++i ) {
        int minj = i;
        for( int j = i; j < n; ++j ) {
            if( dt[j] < dt[minj] ) minj = j;
        }
        if( minj != i ) swap( dt[minj], dt[i] ), ++ans;
    }
}

int main( void ) {
    ios::sync_with_stdio( false );
    int n;
    cin >> n;
    for( int i = 0; i < n; ++i ) cin >> dt[i];
    selectionSort( n );
    for( int i = 0; i < n; ++i ) cout << dt[i] << ( i == n - 1 ? '\n' : ' '  );
    cout << ans << '\n';
    return 0;
}

