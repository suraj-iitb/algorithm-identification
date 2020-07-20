#include <iostream>
#include <algorithm>
using namespace std;
static const int MAX = 100;

void trace( int A[], int N )
{
    for ( int i = 0; i < N; i++ )
    {
        if ( i > 0 ) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

void bubbleSort( int A[], int N )
{
    int count = 0;

    bool flag = true;
    for ( int i = 0; flag; i++ )
    {
        flag = false;
        for ( int j = N-1; j > i; j-- )
        {
            if ( A[j] < A[j-1] )
            {
                swap( A[j], A[j-1] );
                flag = true;
                count++;
            }
        }
    }
    trace( A, N );
    cout << count << endl;
}

int main(void)
{
    int A[MAX], N;

    cin >> N;
    for ( int i = 0; i < N; i++ )
    {
        cin >> A[i];
    }


    bubbleSort( A, N );


    return 0;
}

