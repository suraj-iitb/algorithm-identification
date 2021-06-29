#include <stdio.h>

int main(void){
	
	int n,i,j,k,A[101],M,C=0;
	scanf("%d",&n);
	for (i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	for(k=0;k<n;k++){
		for(i=n-1;i!=0;i--){
			j=i-1;
			if(A[i]<A[j]){
				M=A[i];
				A[i]=A[j];
				A[j]=M;
				C++;
			}
		}
	}
	for(i=0;i<n-1;i++){
		printf("%d ",A[i]);
	}
	printf("%d\n%d\n",A[i],C);
	return 0;
}
