#include <stdio.h>
#include <stdlib.h>

void CountingSort(int *,int *,int *,int,int);

int main(void)
{
	int i,n,k,*A,*B,*C;
	
	scanf("%d",&n);
	A=(int *)malloc(sizeof(int)*(n+1));
	for(i=0;i<n;i++)scanf("%d",&A[i]);
	k=A[0];
	for(i=1;i<n;i++)if(k<A[i])k=A[i];
	B=(int *)malloc(sizeof(int)*(n+1));
	C=(int *)malloc(sizeof(int)*(k+1));
	
	CountingSort(A,B,C,k,n);
	
	for(i=0;i<n;i++){
		printf("%d",B[i]);
		if(i!=n-1)printf(" ");
	}
	printf("\n");
		
		
		free(A);
		free(B);
		free(C);
		
	return 0;
}
void CountingSort(int *A,int *B,int *C, int k,int n){
	int i,j;
	
	for(i=0;i<=k;i++)C[i]=0;
	for(j=0;j<n;j++)C[A[j]]++;
	for(i=1;i<=k;i++)C[i]=C[i]+C[i-1];
	for(j=n-1;j>=0;j--){
		B[C[A[j]]-1]=A[j];
		C[A[j]]--;
	}
	
}
