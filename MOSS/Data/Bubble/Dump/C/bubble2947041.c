#include <stdio.h>
#define N 100

int Bubble(int A[N], int n){

	int count = 0;
	int tmp,i,j;
	
	for(i = 0; i < n; i++){
		for(j = n-1; j > 0; j--){
			if(A[j] < A[j-1]){
				tmp = A[j];
				A[j] = A[j-1];
				A[j-1] = tmp;
				count++;
			}
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

	count = Bubble(A,n);
	
	for ( i = 0; i < n; ++i){
		printf("%d",A[i]);
		if( i != n-1) printf(" ");
	}
		printf("\n%d\n",count);

	return 0;
}
