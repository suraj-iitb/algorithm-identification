#include <bits/stdc++.h>
#define rep( i, a, b ) for( int i = (a); i <= (b); ++i )
#define dep( i, a, b ) for( int i = (a); i >= (b); --i )
using namespace std;
typedef long long ll;
const int N = 5e5+9, INF = 0x3f3f3f3f;
int n, dt[N], ans = 0;

void marge( int dt[], int left, int mid, int right ) {
    int n1 = mid - left;
    int n2 = right - mid;
    int a[n1 + 1], b[n2 + 1];
    for( int i = 0; i < n1; ++i ) a[i] = dt[i + left];
    for( int i = 0; i < n2; ++i ) b[i] = dt[mid + i];
    a[n1] = b[n2] = INF;
    int t1 = 0, t2 = 0;
    for( int i = left; i < right; ++i ) {
        if( a[t1] < b[t2] ) {
            dt[i] = a[t1];
            t1++;
        }
        else {
            dt[i] = b[t2];
            t2++;
        }
        ++ans;
    }
}

void marge_sort( int dt[], int left, int right ) {
    if( right - left > 1 ) {
        int mid = right + left >> 1;
        marge_sort( dt, left, mid );
        marge_sort( dt, mid, right );
        marge( dt, left, mid, right );
    }
}

int main( void ) {
    ios::sync_with_stdio( false );
    int n;
    cin >> n;
    for( int i = 0; i < n; ++i ) cin >> dt[i];
    marge_sort( dt, 0, n );
    for( int i = 0; i < n; ++i ) cout << dt[i] << ( i == n - 1 ? '\n' : ' ' );
    cout << ans << '\n';
    return 0;
}
