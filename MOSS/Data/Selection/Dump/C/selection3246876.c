#include <stdio.h>

int main(void){
	int n,x,i,minj,tmp,count;
	count = 0;
	scanf("%d", &n);
	int A[n];
	for(i=0;i<n;i++){
		scanf("%d", &x);
		A[i] = x;
	}
	for(i=0;i<n;i++){
		minj = i;
		for(int j=i;j<n;j++){
			if(A[j] < A[minj]){
				minj = j;
			}
		}
		if(minj != i){
			tmp = A[i];
			A[i] = A[minj];
			A[minj] = tmp;
			count++;
		}
	}
	for(i=0;i<n;i++){
		printf("%d", A[i]);
		if(i!=n-1){
			printf(" ");
		}else{
			printf("\n");
		}
	}
	printf("%d\n",count);
}

