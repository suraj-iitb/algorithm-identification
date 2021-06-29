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
	int i,j,n,flag,A[100],temp,count=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&A[i]);
	flag = 1;
	// print(A,n);
	while(flag){
		flag = 0;
		for (j=1;j<=n-1;j++){
			if(A[j] < A[j-1]){
				temp = A[j];
				A[j]= A[j-1];
				A[j-1]= temp;
				flag =1;
		count++;
			}
		}
		// print(A,n);
	}
	print(A,n);
	printf("%d\n",count);
	return 0;
}
