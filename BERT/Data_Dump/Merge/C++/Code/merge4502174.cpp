#include<iostream>
#include<limits>
#define MAX 500000
#define SENTINEL 2000000000

int cnt ;
void merge( int A[], int left, int mid, int right )
{
    int i, j, k ;
    int n1, n2 ;

    n1 = mid - left ;
    n2 = right - mid ;

    int L[n1+1], R[n2+1] ;

    for( i = 0 ; i < n1 ; i++ )
        L[i] = A[left+i] ;
    for( i = 0 ; i < n2 ; i++ )
        R[i] = A[mid+i] ;

    L[n1] = SENTINEL ;
    R[n2] = SENTINEL ;

    i = 0 ;
    j = 0 ;
    for( k = left ; k < right ; k++ )
    {
        cnt++ ;
        if( L[i] <= R[j] )
        {
            A[k] = L[i] ;
            i++ ;
        }
        else
        {
            A[k] = R[j] ;
            j++ ;
        }
    }
}

void merge_sort( int A[], int left, int right )
{
    if( left + 1 < right )
    {
        int mid = (left+right)/2 ;
        merge_sort(A, left, mid) ;
        merge_sort(A, mid, right ) ;
        merge(A, left, mid, right ) ;
    }
}

int main() 
{
    int S[MAX], n, i ;
    cnt = 0 ;

    std::cin >> n ;
    for( i = 0 ; i < n ; i++ )
        std::cin >> S[i] ;

    merge_sort(S, 0, n) ;
    for( i = 0 ; i < n ; i++ )
    {
        if(i)
            std::cout << " " ;
        std::cout << S[i] ;
    }
   
    std::cout << std::endl ;

    std::cout << cnt << std::endl ;

    
}

