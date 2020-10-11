#include<stdio.h>

int selectionSort(int A[],int N){
	int i,minj,j,x,cnt = 0;
	for(i = 0;i < N - 1;i++){
		minj = i;
		for(j = i;j < N;j++){
			if(A[j] < A[minj]){
				minj = j;
			}
		}
		x = A[i];
		A[i] = A[minj];
		A[minj] = x;
		
		if(i != minj) cnt++;
	}
	return cnt;
}
		
int main(void){		
	int A[100];
	int N,i,cnt;
	scanf("%d",&N);
	for(i = 0;i < N;i++){
		scanf("%d",&A[i]);
	}
	cnt = selectionSort(A,N);
	
	for(i = 0;i < N;i++){
		if(i > 0) printf(" ");
		printf("%d",A[i]);
	}
	printf("\n");
	printf("%d\n",cnt);
	
	return 0;
}
