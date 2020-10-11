#include <stdio.h>
#define max 101
int main(void){
	int N,i,j,k,A[max],key;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	for(k=0;k<N;k++){
		printf("%d",A[k]);
		if(k!=N-1) printf(" ");
	}
	printf("\n");
	for(i=1;i<N;i++){
		key=A[i];
		j=i-1;
		while(j>=0 && A[j]>key){
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=key;
		for(k=0;k<N;k++){
			printf("%d",A[k]);
			if(k!=N-1) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
