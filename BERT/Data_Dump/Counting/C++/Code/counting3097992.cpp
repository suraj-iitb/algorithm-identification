#include<iostream>
using namespace std;

void CountingSort( int* a, int* b, int n, int k )
{
    int c[k+1];

    for( int i = 0; i <= k; i++ )
        c[i] = 0;

    for( int j = 1; j <= n; j++ )
        c[a[j]]++;

    for( int i = 1; i <= k; i++ )
        c[i] = c[i] + c[i-1];

    for( int j = n; j >= 1; j-- )
    {
        b[c[a[j]]] = a[j];
        c[a[j]]--;
    }
}

int main()
{
    int n, k = 0;

    cin >> n;

    int a[n+1], b[n+1];

    for( int i = 1; i <= n; i++ )
    {   
        cin >> a[i];
        if( k < a[i] )
            k = a[i];
    }

    CountingSort( a, b, n, k );

    for( int i = 1; i < n; i++ )
        cout << b[i] << " ";
    cout << b[n] << endl;

    return 0;
}
