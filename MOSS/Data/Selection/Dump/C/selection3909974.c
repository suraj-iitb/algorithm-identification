#include <stdio.h>

int selectionSort(int A[],int N){
	int count = 0;
	int min;
	int change;
	for(int i = 0;i <N-1;i++){
		min = i;
		for(int j = i;j < N;j++){
			if(A[j] < A[min]){
			min = j;
			}
		}
			change = A[i];
			A[i] = A[min];
			A[min] = change;
			if(i != min)count++;
			
		
	}
	return count;
}
int main(void){
	int n;
	scanf("%d",&n);
	int a[n];
	int c;
	c = 0;
	for(int i=0;i<n;i++){
	scanf("%d",&a[i]);
	}
	c = selectionSort(a , n);
	
	
	for(int i = 0;i<n;i++){
		printf("%d",a[i]);
		
		if(i != n-1)printf(" ");
	}
	printf("\n");
	printf("%d\n",c);
	return 0;
}

