#include <cstdio>
#include <algorithm>

using namespace std;

int main(){

    int n, i, j, k, v;

    scanf("%d", &n);

    int A[n];

    for( i = 0 ; i < n ; i++ ){

        scanf( "%d", &A[i] );

    }

     for( k=0 ; k < n ; k++ ){

        if( k > n-2 ){

            printf("%d\n", A[k] );

         }else{

            printf("%d ", A[k] );

        }
     }

    for( i = 1 ; i < n ; i++ ){

            v = A[i];
            j = i - 1;
    
        while( j >= 0 && A[j] > v ){

                A[j+1] = A[j];

                j--;

        }

        A[j+1] = v;

        for( k=0 ; k < n ; k++ ){


            if( k > n-2 ){

                printf("%d\n", A[k] );

            }else{

                printf("%d ", A[k] );

            }
        }

    }

    return 0;

}
