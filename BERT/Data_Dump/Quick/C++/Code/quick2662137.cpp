#include <cstdio>
#include <cmath>
#include <utility>
#include <vector>

using namespace std;

//????????¢??°???

int partition(  vector<pair< char, int > > &A, int p ,int r){

    int x = A[r].second;
    int i, j;

    i = p - 1;

    for( j = p ; j < r ; j++ ){

        if( A[j].second <= x ){

            i = i + 1;

            swap(A[i], A[j] );

        }

    }

    swap( A[i+1], A[r] );

    return i + 1;

}

void quick_sort(  vector<pair< char, int > > &A, int p, int r){

    int q;

    if( p < r ){

        q = partition( A , p , r );
        quick_sort( A , p , q-1 );
        quick_sort( A , q+1 , r );

    }

}

//??????????????????

int merge( vector<pair< char, int > > &A, int left, int mid, int right){

    int n1, n2, i, j , k ;

    n1 = mid - left;
    n2 = right - mid;

    vector<pair< char, int > > L, R;


    for( i = 0 ; i < n1 ; i++ ){

        L.push_back( make_pair(A[ left + i ].first, A[ left + i ].second) );

    }

    for( i = 0 ; i < n2 ; i++ ){

        R.push_back( make_pair(A[ mid + i ].first, A[ mid + i ].second) );

    }

    L.push_back( make_pair('a', 200000000) );
    R.push_back( make_pair('a', 200000000) );

    i = 0;
    j = 0;

    for( k = left ; k < right ; k++ ){

        if( L[i].second <= R[j].second ){
        
            A[k].first = L[i].first;
            A[k].second = L[i].second;
            i = i + 1;

        }else{
            
            A[k].first = R[j].first;
            A[k].second = R[j].second;
            j = j + 1 ;

        }

    }

}

int mergesort( vector<pair< char, int > > &A, int left, int right){

    int mid;

    if( left + 1 < right ){

        mid = ( left + right ) / 2 ;

        mergesort( A, left, mid );
        mergesort( A, mid, right );

        merge( A , left , mid , right );

    } 

}


//??¬???

int main(){

    char c, trash;

    int n, i, r, j, p, left, right;

    scanf("%d", &n);
    scanf("%c", &trash);

    p = 0;
    left = 0;

    r = n - 1;
    right = n;

    vector<pair< char, int > > A,B;

    for( i = 0; i < n ; i++ ){

        scanf("%c", &c);
        scanf("%d", &j);
        scanf("%c", &trash);

        A.push_back( make_pair( c , j ) );
        B.push_back( make_pair( c , j ) );

    }

    //quick sort

    quick_sort( A, p, r);

    //merge sort

    mergesort( B, left, right );

    int stable = 1;

    for( i = 0; i < n; i++ ){

        if( A[i] != B[i] ) stable = 0;

    }

    if( stable ) printf("Stable\n");
    else printf("Not stable\n");

    for( i = 0 ; i < n ; i++ ){

        printf("%c %d\n", A[i].first, A[i].second);

    }


    return 0;

}
