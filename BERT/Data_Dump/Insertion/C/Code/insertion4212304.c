#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void InsertionSort(int [],int N);

int main(){
  int i,N;
  int *data;
  
  scanf("%d",&N);
  data = (int *)malloc(sizeof(int) * N);

  for (i = 0;i < N;i++)
    scanf("%d",&data[i]);

  InsertionSort(data,N);
  free(data);
  
  return 0;
}

void InsertionSort(int A[],int N){
  int v;
  int i,j,k;

  for (i = 1;i < N;i++){
    for (k = 0;k < N;k++){
      if (k)
        printf(" ");

      printf("%d",A[k]);
    }
    
    printf("\n");
    
    v = A[i];
    j = i - 1;

    while (j >= 0 && A[j] > v){
      A[j + 1] = A[j];
      j--;
    }

    A[j + 1] = v;
  }

  for (k = 0;k < N;k++){
    if (k)
      printf(" ");

    printf("%d",A[k]);
  }
    
  printf("\n");
  
}
