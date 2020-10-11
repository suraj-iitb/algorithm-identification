#include<stdio.h>
#define N 2000000

int main(){
	int i,n;
  int A[N],B[N],C[N];

	scanf("%d",&n);

	for(i=0; i<n; i++){
	  scanf("%d",&A[i]);
	}

	for(i=0; i<N; i++){
		C[i] = 0;
	}

	for(i=0; i<n; i++){
		C[A[i]]++;
	}

	for(i=1; i<N; i++){
		C[i] = C[i] + C[i-1];
	}

	for(i=n-1; i>=0; i--){
		B[C[A[i]]-1] = A[i];
		C[A[i]]--;
	}

	for(i=0; i<n; i++){
		if(i==0) printf("%d",B[i]);
		else printf(" %d",B[i]);
	}

  printf("\n");

	return 0;
}

