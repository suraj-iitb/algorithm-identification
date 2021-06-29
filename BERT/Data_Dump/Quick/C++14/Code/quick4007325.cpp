#include <bits/stdc++.h>
using namespace std;

struct Card
{
        char suit;
        int num;

        Card () {}
        Card ( char suit, int num ) : suit(suit), num(num) {}

        bool operator < ( const Card &d ) const { return ( num < d.num ); }
        bool operator <= ( const Card &d ) const { return ( num <= d.num ); }
        bool operator == ( const Card &d ) const { return ( suit == d.suit && num == d.num ); }
        
        friend istream &operator >> (istream &is, Card &a)
        {
                return ( is >> a.suit >> a.num );
        }

        friend ostream &operator << (ostream &os, const Card &a)
        {
                return ( os << a.suit << " " << a.num );
        }

        static Card INF()
        {
                static const Card inf = Card(' ', (1 << 30) - 1);
                return ( inf );
        }
};

template < typename T >
int Partition(T *A, int p, int r)
{
        T x = A[r];
        int i = p;
        for ( int j = p; j < r; j++ ) {
                if ( A[j] <= x ) {
                        swap(A[i], A[j]);
                        i++;
                }
        }
        swap(A[i], A[r]);
        return ( i );
}

template < typename T >
void Quicksort(T *A, int p, int r)
{
        if ( p < r ) {
                int q = Partition(A, p, r);
                Quicksort(A, p, q - 1);
                Quicksort(A, q + 1, r);
        }
}

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

        L[n1] = T::INF(), L[n2] = T::INF();
        i = 0, j = 0;
        for ( k = l; k < r; k++ ) {
                if ( j >= n2 || L[i] <= R[j] ) A[k] = L[i++];
                else A[k] = R[j++];
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
        Card A[100005], B[100005];
        int idx;

        cin >> n;
        for ( int i = 0; i < n; i++ ) {
                cin >> A[i];
                B[i] = A[i];
        }
        
        Quicksort(A, 0, n - 1);
        Mergesort(B, 0, n);
        
        bool stable = true;
        for ( int i = 0; i < n; i++ ) {
                stable &= (A[i] == B[i]);
        }

        if ( stable ) cout << "Stable" << endl;
        else cout << "Not stable" << endl;

        for ( int i = 0; i < n; i++ ) {
                cout << A[i] << endl;
        }

        return ( 0 );
}

