#include<stdio.h>
#include<stdlib.h>

int n;

void CountingSort(int [],int [], int);

int main(){
  int *A, *B;
  int max=0;
  int i;

  scanf("%d",&n);
  A = (int *)malloc(n * sizeof(int));
  B = (int *)malloc(n * sizeof(int));

  for(i=0; i<n; i++){
    scanf("%d",&A[i]);

    if(max < A[i])
      max = A[i];
  }

  CountingSort(A,B,max+2);

  for(i=0; i<n; i++){
    printf("%d",B[i]);

    if(i<n-1)
      printf(" ");
  }
  printf("\n");
  
  free(A);
  free(B);
  return 0;
}

void CountingSort(int A[],int B[], int k){
  int C[k];
  int i;

  for(i=0; i<k; i++)
    C[i] = 0;

  for(i=0; i<n; i++)
    C[A[i]]++;

  for(i=1; i<k; i++)
    C[i] += C[i-1];

  for(i=n-1; i>=0; i--){
    B[C[A[i]]-1] = A[i];
    C[A[i]]--;
  }
}

