#include <stdio.h>
#define N 100


int selection(int A[N], int n){

	int i,j,min,tmp,k;
	int count = 0;

	for(i = 0; i < n-1; i++){
		min = i;
		for(j = i+1; j < n; j++){
			if(A[j] < A[min]){
				min = j;
			}
		}

		if(A[i] > A[min]){
			tmp = A[i];
			A[i] = A[min];
			A[min] = tmp;
			count++;
		}
	}
	return count;
}


int main(){

	int A[N],n,i,count;

	scanf("%d",&n);

	for(i = 0; i < n; i++){
		scanf("%d",&A[i]);
	}

	count = selection(A,n);

	for ( i = 0; i < n; ++i){
		printf("%d",A[i]);
		if( i != n-1) printf(" ");
	}
	printf("\n%d\n",count);

	return 0;
}
