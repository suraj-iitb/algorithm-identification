#include<stdio.h>
int main(void){
	int N,i,j,v;
	int A[100];
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	for(j=0;j<N-1;j++){
			printf("%d ",A[j]);
	}
	printf("%d\n",A[N-1]);
	for(i=1;i<N;i++){
		v=A[i];
		j=i-1;
		while(0<=j && A[j]>v){
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=v;
		for(j=0;j<N-1;j++){
			printf("%d ",A[j]);
		}
		printf("%d\n",A[N-1]);
	}
	return 0;
}
