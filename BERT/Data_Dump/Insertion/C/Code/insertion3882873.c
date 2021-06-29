#include<stdio.h>

int main(void){
	int N;
	int i,j,v;
	scanf("%d",&N);
	int A[N];
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	for(i=0;i<N;i++){
		v=A[i];
		j=i-1;
		while(j>=0 && A[j]>v){
			A[j+1]=A[j];
			j--;
			A[j+1]=v;
		}
		for(j=0;j<N-1;j++){
			printf("%d ",A[j]);
		}
		for(j=N-1;j<N;j++){
			printf("%d",A[j]);
		}
		printf("\n");
	}
	return 0;
}
