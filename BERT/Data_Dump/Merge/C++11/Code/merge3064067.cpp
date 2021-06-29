#include <bits/stdc++.h>
using namespace std;

int n, a[500010];
int cnt = 0;

int L[250010], R[250010];
const int inf = 2000000000;

void merge( int  l, int m, int r ){
    int n1 = m - l;
    int n2 = r - m;
    for( int i = 0; i < n1; i++ ) L[i] = a[l + i];
    for( int i = 0; i < n2; i++ ) R[i] = a[m + i];

    L[n1] = R[n2] = inf;
    int i = 0, j = 0;
    for( int k = l; k < r; k++ ){
        cnt++;
        if( L[i] <= R[j] ){
            a[k] = L[i++];
        }
        else {
            a[k] = R[j++];
        }
    }
}

void msort( int l, int r ){
    if( l + 1 < r ){
        int m = ( l + r )/ 2;
        msort( l, m );
        msort( m, r );
        merge( l, m, r );
    }
}

int main()
{
    cin >> n;
    for( int i = 0; i < n; i++ ) cin >> a[i];

    msort( 0, n );

    for( int i = 0; i < n; i++ ) cout << ( i ? " " : "" ) << a[i];
    cout << endl << cnt << endl;

    return 0;
}

