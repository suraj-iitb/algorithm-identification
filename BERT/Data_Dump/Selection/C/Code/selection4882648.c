#include<stdio.h>

int selectionSort(int A[], int N){

int minj,tmp,count=0;
for(int i=0; i<N; ++i){
	minj=i;
	for(int j=i; j<N; ++j){
		if(A[j]<A[minj]){
			minj=j;
		}
	}
	if(A[i]>A[minj]) count++;
	
	tmp=A[minj];
	A[minj]=A[i];
	A[i]=tmp;	
}
	for(int i=0; i<N; ++i){
		if(i>0){
			printf(" ");
		}
		printf("%d",A[i]);
	}
	printf("\n");
	printf("%d\n", count);
	
	return 0;
}



int main(){

int N,M;
scanf("%d", &N);
int A[N];
for(int i=0; i<N; ++i){
	A[i]=0;
	scanf("%d", &M);
	A[i]=M;
}
selectionSort(A,N);

return 0;
}

