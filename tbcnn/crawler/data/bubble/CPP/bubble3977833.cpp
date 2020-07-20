#include<stdio.h>

#define N 100




int main(void){
	
	int n,A[N],count;

	
	scanf("%d",&n);

	for(int i=0;i<n;i++){

		scanf("%d",&A[i]);

		}
	
		int flag=1;
	
	
	while(flag){
		flag=0;
	
	for(int j=n-1;j>0;j--){
		
		if(A[j]<A[j-1]){
			
			int temp=A[j];
			A[j] = A[j-1];
			A[j-1]=temp;
			
			flag=1;
			count++;
			
		}
	}
	
	}
	
	for(int i=0;i<n-1;i++){

			printf("%d ",A[i]);
			
		
		}
	
	printf("%d\n",A[n-1]);
	printf("%d\n",count);
	
	return 0;
}



	
	
