#include <stdio.h>

#define N 100

void trace(int[], int);

int main() {
  
  int i, j, tmp, length;
  int A[N + 1];
  scanf("%d", &length);

  for(i = 0; i < length; i++) {
    scanf("%d", &A[i]);
  }
    trace(A, length);
    for(j = 1; j < length; j++) {
      tmp = A[j];
      i = j - 1;
      while((i >= 0) && (A[i] > tmp)) {
	A[i + 1] = A[i];
	i--;
      }
      A[i + 1] = tmp;
      
      trace(A, length);
    }
    
    return 0;
  }

  void trace(int A[], int length) {
    int i;
    for(i = 0; i < length; i++){
      if(i > 0) {
	printf(" ");
      }
      printf("%d", A[i]);
    }
    printf("\n");
  }
