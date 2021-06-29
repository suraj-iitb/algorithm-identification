#include <stdio.h>


int bubbleSort(int A[], int N);

int main() {
  int N;
  int A[100];
  int result;
  int i;
  int count;

  scanf("%d", &N);
  for(i = 0; i < N; i++)
    {scanf("%d", A+i);
    }

  result = bubbleSort(A, N);
  
  for(i = 0; i < N; i++){
    if(i>0) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
    printf("%d\n", result);

  return 0;
}

int bubbleSort(int A[], int N) {
  int j;
    
  int flag = 1;
  int tench;
    
  int result = 0;



  while(flag) {
    flag = 0;
    for(j = N-1; j > 0; --j) {
      
      if(A[j] < A[j-1]) {
	
        tench = A[j];
        A[j] = A[j-1];
	
        A[j-1] = tench;
        flag = 1;
	
        ++result;
      }
    }
  }
  return result;
}


