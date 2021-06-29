#include <stdio.h>
#include <stdlib.h>

#define MAX 2000001
#define VMAX 10000

void countingSort(unsigned short a[], unsigned short b[], int n) {
  int i, j, count[VMAX+1];
  for(i=0;i<=VMAX;i++) {
    count[i] = 0;
  }
  for(i=1;i<=n;i++) {
    count[a[i]]++;
	}
  for(i=1;i<=VMAX;i++) {
    count[i] = count[i] + count[i-1];
  }
  for(j=1;j<=n;j++) {
    b[count[a[j]]] = a[j];
    count[a[j]]--;
  }
}

int main(void) {
  int i, N;
  unsigned short *A, *B;
  
  scanf("%d",&N);
  A = malloc(sizeof(short)*N+1);
  B = malloc(sizeof(short)*N+1);
  
  for(i=1;i<=N;i++) {
    scanf("%hu",&A[i]);
  }
  
  countingSort(A,B,N);
  
  for(i=1;i<=N;i++) {
    if(i>1) printf(" ");
    printf("%d",B[i]);
  }
  printf("\n");
  
  return 0;
}
