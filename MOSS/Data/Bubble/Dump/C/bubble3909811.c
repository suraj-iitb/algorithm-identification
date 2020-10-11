#include <stdio.h>

int bubbleSort(int A[],int N );
int main(void){
	int n;
	scanf("%d",&n);
	int a[n];
	int c;
	c = 0;
	for(int i;i<n;i++){
	scanf("%d",&a[i]);
	}
	c = bubbleSort(a , n);
	
	
	for(int i = 0;i<n;i++){
		printf("%d",a[i]);
		
		if(i != n-1)printf(" ");
	}
	printf("\n");
	printf("%d\n",c);
	return 0;
}

int bubbleSort(int A[],int N){
	int flag = 1;
	int change;
	int count = 0;
	while(flag){
		flag = 0;
		
		for(int j = N-1;j > 0;j--){
			if(A[j] < A[j-1]){
				change = A[j];
				A[j] = A[j-1];
				A[j-1] = change;
				flag = 1;
				count++;
			}
		}
	}
	return count;
}
