#include<stdio.h>

void bubblesort(int*,int);

int main()
{
    int N;
    scanf("%d",&N);
    int A[N], i;
    for(i=0; i<N; i++){
        scanf("%d",&A[i]);
    }
    bubblesort(A,N);
    
    return 0;
}

void bubblesort(int *A, int N)
{
 
 int i, j, temp, count=0;
 
 for(i=0; i<N-1; i++){
     for(j=N-1; j>i; j--){
         if(A[j] < A[j-1]){
             temp = A[j];
             A[j] = A[j-1];
             A[j-1] = temp;
             count++;
         }
     }
 }
 
 printf("%d",A[0]);
 for(i=1; i<N; i++){
     printf(" %d",A[i]);
 }
 printf("\n%d\n",count);
}
