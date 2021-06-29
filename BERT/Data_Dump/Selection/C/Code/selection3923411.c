#include <stdio.h>

int selectionSort(int A[],int N){
	int i,j,minj,tag;
	int ss=0;
	
	for(i=0;i<N-1;i++){
		minj=i;
		for(j=i;j<N;j++){
			if(A[j]<A[minj]){
				minj=j;
			}
		}
		tag=A[i];
		A[i]=A[minj];
		A[minj]=tag;
		if(i!=minj){
			ss++;
		}
	}
	return ss;
}

int main(void){
	int N,ss,i;
	int A[100];
	
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	
	ss=selectionSort(A, N);
	
	for(i=0;i<N;i++){
		if(i>0){
			printf(" ");
		}
		printf("%d",A[i]);
	}
	
	printf("\n");
	printf("%d\n",ss);
	return 0;
}
