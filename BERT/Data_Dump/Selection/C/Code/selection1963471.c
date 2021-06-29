#include<stdio.h>

int main(void)
{
	int i,j,n,temp,minj,count = 0;
	int A[100];
	
	scanf("%d",&n);
	for(i = 0;i < n;i++){
		scanf("%d",&A[i]);
	}
	for(i = 0;i < n;i++){
		minj = i;
		for(j = i;j < n;j++){
			if(A[j] < A[minj]){
				minj = j;
			}
		}
		if(i != minj)count++;
		temp = A[i];
		A[i] = A[minj];
		A[minj] = temp;
	}
	for(i = 0;i < n;i++){
		if(i != 0 && i < n)printf(" ");
		printf("%d",A[i]);
	}
	printf("\n");
	printf("%d\n",count);
	return 0;
}
