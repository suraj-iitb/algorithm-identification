#include <stdio.h>
void bubbleSort(int A[] ,int N );
int main(){
  int i, j, A[100];

  scanf("%d",&i);
  for(j = 0; j < i; j++) scanf("%d",&A[j]);
  bubbleSort(A , i);
 
  return 0;
}

void bubbleSort(int A[] ,int N){
  int j, change, flag = 1, count = 0;
  while(flag == 1){
    flag = 0;
    for(j = N-1; j > 0; j--){
      if(A[j] < A[j-1]){
	change = A[j];
	A[j] = A[j-1];
	A[j-1] = change;
	flag = 1;
	count++;
      }
    }
  }
  for(j = 0; j < N; j++){
    printf("%d",A[j]);
    if(j != N-1) printf(" ");
  }
  printf("\n");
  printf("%d",count);
  printf("\n");
}

