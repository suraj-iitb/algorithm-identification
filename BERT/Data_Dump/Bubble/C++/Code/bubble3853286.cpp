#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+9, INF = 0x3f3f3f3f;
int dt[105], ans = 0;

void bubbleSort( int n ) {
    bool ok = true;
    while( ok ) {
        ok = false;
        for( int i = n - 1; i >= 1; --i ) {
            if( dt[i] < dt[i - 1] ) swap( dt[i], dt[i - 1] ), ok = true, ++ans;
        }
    }
}

int main( void ) {
    ios::sync_with_stdio( false );
    int n;
    cin >> n;
    for( int i = 0; i < n; ++i ) cin >> dt[i];
    bubbleSort( n );
    for( int i = 0; i < n; ++i ) cout << dt[i] << ( i == n - 1 ? '\n' : ' ' );
    cout << ans << '\n';
    return 0;
}

