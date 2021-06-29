#include <stdio.h>
void trace (int A[],int N){
	int i;
	for(i = 0; i < N; i++){
		if(i > 0){printf(" ");}
		printf("%d",A[i]);
	}
	printf("\n");
	return;
}
void sort(int A[],int N){
	int i,j,v;
	for(i = 1; i < N; i++){
		v = A[i];
		j = i-1;
		while(j >= 0 && A[j] > v){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;
		trace(A,N);
	}
	return;
}
int main(void){
	int r,R[100],i;
	scanf("%d",&r);
	for(i = 0; i < r; i++){scanf("%d",&R[i]);}
	trace(R,r);
	sort(R,r);
	return 0;
}
