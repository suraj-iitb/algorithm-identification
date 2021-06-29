#include<stdio.h>


int bubbleSort(int A[], int N){
  int i, j, sw=0,s=0;

  for (i = 0; i < N - 1 ; i++) {
    for (j = N - 1; j > i; j--) {
      if (A[j-1] > A[j]) {
        s = A[j-1];
        A[j-1] = A[j];
        A[j] = s;
	sw++;
  }
}

  }

  return sw;
}




int main(){

  int A[100],N=0,sw=0,i;
  scanf("%d",&N);

  for(i =0; i < N; i++) scanf("%d",&A[i]);

  sw = bubbleSort(A,N);

  printf("%d",A[0]);
  for(i =1; i < N; i++) printf(" %d",A[i]);
    
   printf("\n");

   printf("%d\n",sw);

   return 0;
}



