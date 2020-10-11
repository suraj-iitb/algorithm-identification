#include <stdio.h>

int main(void)
{
    int n ,m;
    int A[1000];

        scanf("%d" , &n);
    
    for ( m = 0 ; m < n ; m++) {
            scanf("%d" , &A[m]);
    }
    
    /*Buble Sort*/
    int flag = 1;
    int i = 0;
    int j ,temp ,count;
    
    do {
        flag = 0;
        for ( j = n - 1 ; j >= i + 1 ; j-- ) {
            if ( A[j - 1] > A[j] ) {
                /*swap*/
                temp = A[j - 1];
                A[j - 1] = A[j];
                A[j] = temp;
                flag = 1;
                count++;
            }
        }
        i++;
    }while ( flag == 1 );
    
    for (int s = 0 ; s < n - 1 ; s++ )
        printf("%d " , A[s]);
    printf("%d\n" , A[n - 1]);
    printf("%d\n" , count);
    
    return 0;
}

