#include<stdio.h>

int bubbleSort(int A[], int N){
  int i, j, v, sw = 0;
  int flag = 1;
  for(i=0; flag; i++){
    flag = 0;
    for(j=N-1; j>=i+1; j--){
      if(A[j]<A[j-1]){
	v = A[j];
	A[j] = A[j-1];
	A[j-1] = v;
	flag = 1;
	sw++;
      }
    }
  }

  return sw;
}

int main(){
  int i, A[100], N, sw;
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

     
      
	
     
      
     

