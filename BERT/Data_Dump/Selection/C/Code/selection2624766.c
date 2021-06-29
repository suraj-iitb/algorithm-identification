#include <stdio.h>
void print(int A[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d",A[i]);
		if(i<n-1)
		printf(" ");
	}
	printf("\n");
}

int main(void){

	int i,j,A[200],count=0,n,minj,temp;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&A[i]);
	for(i=0;i<n;i++){
		minj = i;
		for(j=i;j<n;j++){
			if(A[j] < A[minj]) minj = j;
		}
		if(A[i]!=A[minj])count++;
		temp = A[i];
		A[i]= A[minj];
		A[minj] = temp;
	}
	print(A,n);
	printf("%d\n",count);
	return 0;
}
