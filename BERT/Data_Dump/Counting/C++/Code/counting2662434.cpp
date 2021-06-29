#include <cstdio>
#include <cmath>
#include <utility>
#include <vector>

using namespace std;

//????????¢??°???

#define nmax 10005

int Countingsort( int A[], int B[], int n){

    int i, j;

    int C[ nmax ] = {};

    //C[i]???i???????????°????¨????

    for( j = 0 ; j < n ; j++ ){

        C[ A[j] ]++;

    }


    //C[i]????´???????

    for( j = 1; j < nmax ; j++ ){

        C[j] = C[j] + C[j-1];

    }

    for( j = n-1; j >= 0; j-- ){

        B[ C[ A[j] ] ] = A[j];

        C[ A[j] ]--;

    } 


    for( i = 1 ; i <= n ; i++ ){

        if( i > 1 ) printf(" ");

        printf("%d", B[i]);

    }

    printf("\n");

}


//??¬???

int main(){

    int n, i;

    scanf("%d", &n);

    int A[n], B[n+1] = {};

    for( i = 0; i < n ; i++ ){

        scanf("%d", &A[i]);
        
    }

    Countingsort( A, B, n);

    return 0;

}
