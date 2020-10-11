#include<stdio.h>

void showArray(int A[],int N){
	int i;
	for(i=0;i<N-1;i++)
		printf("%d ",A[i]);
	printf("%d\n",A[N-1]);
}

void bubbleSort(int A[],int N){
	int i;
	int flag=1;
	int count=0;
	while(flag){
		flag=0;
		for(i=N-1;i>0;i--){
			if(A[i]<A[i-1]){
				int temp=A[i];
				A[i]=A[i-1];
				A[i-1]=temp;
				flag=1;
				count++;
			}
		}
	}
	
	showArray(A,N);
	printf("%d\n",count);
}



int main(void){
		int n;
		int array[101];
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&array[i]);

		bubbleSort(array,n);
		
			
		return 0;
}
