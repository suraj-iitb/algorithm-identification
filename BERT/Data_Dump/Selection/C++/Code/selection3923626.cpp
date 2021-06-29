#include<stdio.h>

#define N 100




int main(void){
	
	int n,A[N],min,temp,count;

	
	scanf("%d",&n);

	for(int i=0;i<n;i++){

		scanf("%d",&A[i]);

		}
	count = 0;
	
	for(int i=0;i<n;i++){
		
		min = i;
		
		for(int j=i;j<n;j++){
			
			if(A[j]<A[min]){
				
				min = j;
			}
		}
			if(i != min){
		
				temp =A[i];
				A[i] =A[min];
				A[min]=temp;
				
			
				count++;
			}
			
		
		}
	
			for(int i=0;i<n-1;i++){

			printf("%d ",A[i]);
			
		
		}
	
	printf("%d\n",A[n-1]);
	printf("%d\n",count);
	
	return 0;
}



	
	
