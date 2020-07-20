#include <stdio.h>
 
void output( int A[], int N )
{
    int i;
 
    for( i = 0; i < N; i++ ) {
    printf( "%d", A[i] );
    if(i!=N-1)printf(" ");
    }
    printf( "\n" );
};
 
void bubbleSort( int A[], int N )
{
    int i, j, temp,change;
    change=0;
    for( i = 0; i < N-1; i++ ) {
        for( j = N-1; j > i; j-- ) {
            if( A[j-1] > A[j] ) {
                 
                temp = A[j];
                A[j] = A[j-1];
                A[j-1] = temp;
                change=change+1;
                
            }
        }
     
    }
    output( A, N );
    printf("%d\n",change);
};
 
int main(void)
{
    int A[100], N, i;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&(A[i]));
         
    }
   
 
  
    bubbleSort(A, N);
  
     
}
