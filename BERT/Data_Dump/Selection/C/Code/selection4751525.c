#include <stdio.h>
int sort(int A[],int N){
	int i,j,t,sw = 0,minj;
	for(i = 0; i < N-1; i++){
		minj = i;
		for(j = i; j < N; j++){
			if(A[j] < A[minj]) minj = j;
		}
		t = A[minj]; A[minj] = A[i]; A[i] = t;
		if(i != minj) sw++;
	}
	return sw;
}
int main(void){
	int r,R[100],i,sw;
	scanf("%d",&r);
	for(i = 0; i < r; i++) scanf("%d",&R[i]);
	sw = sort(R,r);
	for(i = 0; i < r; i++) {
	    if(i > 0) printf(" ");
	    printf("%d",R[i]);
	}
	printf("\n%d\n",sw);
	return 0;
}

