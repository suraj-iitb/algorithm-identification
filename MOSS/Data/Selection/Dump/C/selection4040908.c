#include <stdio.h>
void selectionSort(int A[], int N);
int main(){
  int i, j ,A[100];

  scanf("%d",&i);
  for(j = 0; j < i; j++) scanf("%d",&A[j]);
  selectionSort(A ,i);
  
  return 0;
}

void selectionSort(int A[], int N){
  int i, j, minj, change, count = 0;
  for(i = 0; i < N-1; i++){
    minj = i;
    for(j = i; j < N; j++){
      if(A[j] < A[minj]) minj = j;
    }
    change = A[i];
    A[i] = A[minj];
    A[minj] = change;
    if(i != minj) count++;
  }
  
  for(j = 0; j < N; j++){
    printf("%d",A[j]);
    if(j != N-1) printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
}

