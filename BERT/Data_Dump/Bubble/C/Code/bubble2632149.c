#include<stdio.h>

int main(void){
	int X,Y, N;
	int A[1000];
	int i=0;
	//while((scanf("%d",&X))!='\n'){
	//	N=X; //????´???°
	//}
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%d",&A[i]);
	}
	int change=0; //???????????°
	for(int i=0; i< N-1; i++){
		for(int j=N-1; j>i; j--){
			if(A[j-1] > A[j]){
				int stock = A[j];
				A[j] = A[j-1];
				A[j-1] = stock;
				change++;
			}
		}
	}

	for(i=0; i<N; i++){
		if(i>0){
			printf(" ");
		}
		printf("%d",A[i]);
	}
	printf("\n%d\n",change);
}
