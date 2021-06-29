#include<stdio.h>
int main(){
	int A[100],N,i,j,minj,b,c=0;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	for(i=0;i<N;i++){
		minj=i;
		for(j=i;j<N;j++){
			if(A[j]<A[minj]){
				minj=j;
			}
		}
		if(A[i]>A[minj]){
			b=A[i];
			A[i]=A[minj];
			A[minj]=b;
			c++;
		}
	}
	for(i=0;i<N;i++){
		if(i>0){
			printf(" ");
		}
		printf("%d",A[i]);
	}
	printf("\n");
	printf("%d\n",c);
	return 0;
}
