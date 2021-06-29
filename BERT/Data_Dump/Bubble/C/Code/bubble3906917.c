#include <stdio.h>
int bubbleSort(int A[],int N);
int main(void)
{
	int i,n,result;
	scanf("%d", &n);
	int a[n];
	
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	
	result=bubbleSort(a,n);
	
	for(i=0; i<n; i++){
		if(i < n-1){
			printf("%d ",a[i]);
		}
		else{
			printf("%d",a[i]);
		}
	}
	printf("\n");
	printf("%d\n", result);
	
	return 0;
}
int bubbleSort(int A[],int N){
	int result=0,flag = 1,tmp;
	for(int i = 0; flag; i++){
		flag=0;
		for(int j = N-1; j>= i + 1; j--){
			if(A[j] < A[j-1]){
				tmp=A[j];
				A[j]=A[j-1];
				A[j-1]=tmp;
				flag=1;
				result++;
			}
		}
	}
	return result;
}

