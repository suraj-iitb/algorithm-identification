#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

int n;
int C[VMAX+1];

void CountingSort(unsigned short *A, unsigned short *B, int  k){
	int i, j;
	for(i=0; i<=k; i++) C[i] = 0;
	
	/* C[i] に i の出現数を記録する */
	for(j=1; j<=n; j++) C[A[j]]++;
	
	/* C[i] に i 以下の数の出現数を記録する*/
	for(i=1; i<=k; i++) C[i]=C[i]+C[i-1];
	
	for(j=n; j>0; j--){
		B[C[A[j]]] = A[j];
		C[A[j]]--;
	}
}

int main(){
  unsigned short *A, *B;
  int i, k=-1;

  scanf("%d", &n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

	/* your code */
	for(i=1; i<=n; i++) scanf("%hd", &A[i]);
	for(i=1; i<=n; i++){
		if(k<A[i]) k=A[i];
	}
	CountingSort(A, B, k);
	
	for(i=1; i<n; i++) printf("%hu ", B[i]);
	printf("%hu\n", B[n]);

  return 0;
}
