#include<iostream>
using namespace std;

void merge( int* A, int left, int mid, int right, int& c )
{
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1+1], R[n2+1];

    for( int i = 0; i <= n1 - 1; i++ )
        L[i] = A[left + i];
    for( int i = 0; i <= n2 - 1; i++ )
        R[i] = A[mid + i];

    L[n1] = 2000000000;
    R[n2] = 2000000000;

    int i = 0, j = 0;
    for( int k = left; k <= right - 1; k++ )
    {
        c++;
        if( L[i] <= R[j] )
        {
            A[k] = L[i];
            i = i + 1;
        }
        else 
        {
            A[k] = R[j];
            j = j + 1 ;
        }
    }
}

void mergeSort( int* A, int left, int right, int& c )
{
    if( left + 1 < right )
    {
        int mid = ( left + right ) / 2;
        mergeSort( A, left, mid, c );
        mergeSort( A, mid, right, c );
        merge( A, left, mid, right, c );
    }
}

int main()
{
    int n, cnt = 0;

    cin >> n;

    int s[n];

    for( int i = 0; i < n; i++ )
        cin >> s[i];
    
    mergeSort( s, 0, n, cnt );

    for( int i = 0; i < n - 1; i++ )
        cout << s[i] << " ";
    cout << s[n-1] << "\n" << cnt << endl;

    return 0;
}
