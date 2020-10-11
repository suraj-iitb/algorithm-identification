#include <stdio.h>

int main(){
  int A[100];
  int N;
  int i, j, count=0;

  scanf("%d\n",&N);
  for(i = 0 ; i < N ; i++){
    scanf("%d",&A[i]);
  }

  for(i = 0 ; i < N ; i++){
    int min = i;
    for(int j = i ; j < N ; j++){
      if(A[j] < A[min]){
        min = j;
      }
    }
    int temp = A[i];
    A[i] = A[min];
    A[min] = temp;
    if(i != min) count++;
  }

  for(i = 0 ; i < N ; i++){
    if(i < N-1) printf("%d ",A[i]);
    else printf("%d",A[i]);
  }

  printf("\n");
  printf("%d\n",count);

  return 0;
}
