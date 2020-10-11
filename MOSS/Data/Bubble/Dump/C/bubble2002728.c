#include <stdio.h>

int bubbleSort (int A[], int N) {
	int flag = 1;
	int i = 0,j,token,time=0;
	
	while (flag) {
		flag = 0;
		for(j=N-1; j>=i+1; j--) {
			if(A[j]<A[j-1]) {
				token = A[j-1];
				A[j-1] = A[j];
				A[j] = token;
				flag = 1;
				time ++;
			}
		}
		i++;
	}
	return time;
}

void trace (int A[],int N) {
	int i;
	for(i=0; i<N; i++) {
		if(i>0) printf(" ");
		printf("%d",A[i]);
	}
	printf("\n");
}
		

int main(void) {
	int N,i,time;
	int A[100];
	scanf("%d",&N);
	for(i=0; i<N; i++) {
		scanf("%d",&A[i]);
	}
	
	time = bubbleSort(A,N);
	trace(A,N);
	printf("%d\n",time);
	
	return 0;
}
