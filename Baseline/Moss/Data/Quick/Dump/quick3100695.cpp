#include<iostream>
using namespace std;

void exchange( int* a, char* b, int x, int y )
{
    int temp1 = a[x];
    a[x] = a[y];
    a[y] = temp1;

    char temp2 = b[x];
    b[x] = b[y];
    b[y] = temp2;
}

int partition( int* a, char* b, int p, int r )
{
    int x = a[r];
    int i = p - 1;

    for( int j = p; j <= r - 1; j++ )
    {
        if( a[j] <= x )
        {
            i = i + 1;
            exchange( a, b, i, j );
        }
    }
    exchange( a, b, i + 1, r );

    return i + 1;
}

void quickSort( int* a, char* b, int p, int r )
{
    if( p < r )
    {
        int q = partition( a, b, p, r );
        quickSort( a, b, p, q - 1 );
        quickSort( a, b, q + 1, r );
    }
}

void merge( int* a, char* b, int left, int mid, int right )
{
    int LS = mid - left + 1;
    int RS = right - mid + 1;

    int L[LS], R[RS];
    char L2[LS], R2[RS];

    for( int i = 0; i < LS - 1; i++ )
    {
        L[i] = a[i+left];
        L2[i] = b[i+left];
    }
    for( int i = 0; i < RS - 1; i++ )
    {
        R[i] = a[i+mid];
        R2[i] = b[i+mid];
    }

    L[LS-1] = 2000000000;
    R[RS-1] = 2000000000;

    int i = 0, j = 0;
    for( int k = left; k < right; k++ )
    {
        if( L[i] > R[j] )
        {
            a[k] = R[j];
            b[k] = R2[j];
            j++;
        }
        else
        {
            a[k] = L[i];
            b[k] = L2[i];
            i++;
        }
    }
}

void mergeSort( int* a, char* b, int left, int right )
{
    if( left + 1 < right )
    {
        int mid = ( left + right ) / 2;
        mergeSort( a, b, left, mid );
        mergeSort( a, b, mid, right );
        merge( a, b, left, mid, right );
    }
}

int main()
{
    int n;

    cin >> n;

    int a1[n+1], a2[n+1];
    char b1[n+1], b2[n+1];

    for( int i = 1; i <= n; i++ )
    {
        cin >> b1[i];
        b2[i] = b1[i];
        cin >> a1[i];
        a2[i] = a1[i];
    }

    quickSort( a1, b1, 1, n );              //安定かどうかわからない
    mergeSort( a2, b2, 1, n + 1);           //安定なソート

    bool judge = true;

    for( int i = 1; i <= n; i++ )           //mergeSortの結果とquickSortの結果を比較して、安定かどうかを判定
    {
        if( b1[i] != b2[i] )
        {
            judge = false;
            break;
        }
    }

    if( judge == true )
        cout << "Stable" << endl;
    else
        cout << "Not stable" << endl;

    for( int i = 1; i <= n; i++ )           //quickSortの結果を出力
    {
        cout << b1[i] << " ";
        cout << a1[i] << endl;
    }

    return 0;
}
