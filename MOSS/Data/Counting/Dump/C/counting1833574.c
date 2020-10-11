#include<stdio.h>

void countingSort(int);

int A[2000001],B[20000001],C[10001],n=0;

int main(){

	int i,j,t;

	scanf("%d",&n);

	for(i=0 ; i<n ; i++){
		scanf("%d",&A[i]);

		if(t<A[i])t=A[i];

	}

	countingSort(t);

	for(i=1; i<=n-1 ;i++){
			printf("%d ",B[i]);
	}
	  printf("%d",B[i]);
	  printf("\n");
		

		return 0;
	}

	void countingSort(int k){

		int i,j;

		for(i=0 ; i<=k;i++){
			C[i]=0;
		}

		for(j=0 ; j<n ; j++){
			C[A[j]] = C[A[j]]+1;
		}

		for(i=0 ; i<=k ; i++){
			C[i] = C[i]+C[i-1];
		}

		

		for(j=n-1 ; j>=0 ; j--){
			B[C[A[j]]] = A[j];
			C[A[j]] = C[A[j]]-1;
}
}
