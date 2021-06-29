#include <stdio.h>
int selectionSort(int A[],int N);
int main(void)
{
	int i,n,result;
	scanf("%d", &n);
	int a[n];
	
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	result = selectionSort(a,n);
	
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

int selectionSort(int A[], int N)
{
	int i,j,tmp,result=0,minj;
	
	for(i=0; i<= N-1; i++){
		minj = i;
		for(j=i; j<= N-1; j++){
			if(A[j] < A[minj]){
				minj =j;
			}
		}
		tmp=A[i];
		A[i]=A[minj];
		A[minj]=tmp;
		if(i != minj){
			result++;
		}
	}
	return result;
}

