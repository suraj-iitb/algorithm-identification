#include <stdio.h>

int main(void) {
	int n,swaps=0;
	scanf(" %i",&n);
	int A[n];
	for(int i=0;i<n;i++){
		scanf(" %i",&A[i]);
	}
	
	for(int i=0;i<=n-1;i++){
		for(int j=n-1;j>=i+1;j--){
			if(A[j]<A[j-1]){
				int tmp=A[j];
				A[j]=A[j-1];
				A[j-1]=tmp;
				swaps++;
			}
		}
	}
	
	for(int i=0;i<n;i++){
		if(i==n-1){
			printf("%i\n",A[i]);
		}else{
			printf("%i ",A[i]);
		}
	}
	printf("%i\n",swaps);
	return 0;
}
