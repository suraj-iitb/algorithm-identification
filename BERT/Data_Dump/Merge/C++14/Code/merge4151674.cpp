#include <bits/stdc++.h>
using namespace std;

constexpr int INF = (1 << 30) - 1;
int cnt = 0;
template < typename T >
void Merge(T *A, int l, int m, int r)
{
        int i, j, k;
        int n1 = m - l;
        int n2 = r - m; 
        
        auto L = make_unique < T[] > (n1 + 2);
        auto R = make_unique < T[] > (n2 + 2);

        for ( i = 0; i < n1; i++ ) L[i] = A[l + i];
        for ( i = 0; i < n2; i++ ) R[i] = A[m + i];

        L[n1] = INF, L[n2] = INF;
        i = 0, j = 0;
        for ( k = l; k < r; k++ ) {
                if ( j >= n2 || L[i] <= R[j] ) A[k] = L[i++];
                else A[k] = R[j++];
                cnt++;
        }
}

template < typename T >
void Mergesort(T *A, int l, int r) 
{
        if ( l + 1 < r ) {
                int m = (l + r) / 2;
                Mergesort(A, l, m);
                Mergesort(A, m, r);
                Merge(A, l, m, r);
        }
}

int main()
{
        int n;
        int A[500005];

        cin >> n;
        for ( int i = 0; i < n; i++ ) cin >> A[i];
        
        Mergesort(A, 0, n);
        
        cout << A[0];
        for ( int i = 1; i < n; i++ ) cout << " " << A[i];
        cout << endl;
        cout << cnt << endl;

        return ( 0 );
}

