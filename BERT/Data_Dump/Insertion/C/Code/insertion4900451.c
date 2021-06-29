#include <stdio.h>

int main (void)
{
    int N,i;
    scanf("%d",&N);
    int A[100];
    for(i=0;i<N;i++){
      scanf("%d",&A[i]);
      }
   
   line(A,N);
   insertionSort(A,N);
   
   return 0;
}

void line (int A[],int N)
{
    int i;
    for(i=0;i<N;i++){
        if(i>=1){
           printf(" ");
        }
           printf("%d",A[i]);
           
    }
  printf("\n");
}

void insertionSort(int A[],int N)// N個の要素を含む0-オリジンの配列A
{
  int i,v,j;
  for(i=1;i<N;i++){
     v = A[i];
    j = i - 1;
    while( j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
      }
    A[j+1] = v;
  	line (A,N);
    }
}
