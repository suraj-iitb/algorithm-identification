#include<iostream>
using namespace std;

int SelectionSort( int* a, int b )
{
    int min, count = 0;

    for( int i = 0; i <= b - 1; i++ )
    {
        min = i;
        for( int j = i; j <= b - 1; j++ )
        {
            if( a[min] > a[j] )
                min = j;
        }
        if( min != i )
        {
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
            count++;
        }
    }
    return count;
}

int main()
{
    int n, c;

    cin >> n;

    int r[n];

    for( int i = 0; i < n; i++ )
        cin >> r[i];

    c = SelectionSort( r, n );

    for( int i = 0; i < n - 1; i++ )
        cout << r[i] << " ";
    cout << r[n-1] << endl;

    cout << c << endl;

    return 0;
}
