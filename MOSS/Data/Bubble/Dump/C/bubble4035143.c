#include <stdio.h>

int bubbleSort(int A[], int N){
  int sw=0, i, j, flag=1, swap;
  for(i=0; flag; i++){
    flag = 0;
    for(j=N-1; j>=i+1; j--){
      if(A[j]<A[j-1]){
	//swap(A[j], A[j-1]);
	swap = A[j];
	A[j] = A[j-1];
	A[j-1] = swap;
	flag = 1;
	sw++;
      }
    }
  }
  return sw;
}

int main(){
  int A[100], N, sw, i;
  scanf("%d", &N);
  
  for(i=0; i<N; i++) scanf("%d", &A[i]);

  sw = bubbleSort(A, N);
  
  for(i=0; i<N; i++){
    if(i) printf(" ");
    printf("%d", A[i]);
  }

  printf("\n");
  printf("%d\n", sw);
  return 0;
}

