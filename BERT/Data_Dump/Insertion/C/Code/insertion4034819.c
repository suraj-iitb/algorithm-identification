#include <stdio.h>

void insertionSort(int A[],int N);
  
int main(){
  int i,j;
  int A[1000];
  int N;

  scanf("%d",&N);
  for( i = 0; i < N; i++){
    scanf("%d",&A[i]);
  }
  
  insertionSort(A,N);

  
  return 0;


}

void insertionSort(int A[],int N)
{
  int i,k;
  int v,j;
   for(k = 0; k < N; k++){
     if(k>0) printf(" ");
      printf("%d",A[k]);
   }
   printf("\n");
  for(i = 1; i < N; i++){
    v = A[i];
    j = i - 1;

    while( j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    for(k = 0; k < N; k++){
      if(k>0) printf(" ");
      printf("%d",A[k]);
      /*     printf(" ");*/
    }
    printf("\n");
  }
}
  

