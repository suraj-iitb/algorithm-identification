#include <stdio.h>

#define MAX 2000001

int A[MAX],C[10001],B[MAX];
int n;


void CountingSort(){
	
	int i,j;
	for(i=0;i<10001;i++){ C[i] = 0; }
	for(j=1;j<=n;j++){ C[A[j]]++; }
	for(i=1;i<10001;i++){ C[i] = C[i] + C[i-1]; }
	for(j=1;j<=n;j++){ 
		B[C[A[j]]] = A[j]; 
		C[A[j]]--;
	 }

}

int main(void){

	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){ scanf("%d",&A[i]); }
	CountingSort();
	for(i=1;i<=n;i++){ 
		if(i > 1) printf(" ");	
		printf("%d",B[i]); 
	}
	printf("\n");

return 0;

}

