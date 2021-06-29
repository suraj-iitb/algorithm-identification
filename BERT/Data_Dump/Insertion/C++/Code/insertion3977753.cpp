#include<stdio.h>

#define N 100


int main(void){

	int n,v,j;	
	int A[N];

	scanf("%d",&n);	

	for(int i= 0;i<n;i++){

		scanf("%d",&A[i]);

		}

		for(int i=0;i<n-1;i++){

				printf("%d ",A[i]);
				
		
		}
	
		printf("%d\n",A[n-1]);
	for(int i=1;i<n;i++){

		v=A[i];
		j=i-1;

		while(j>=0 && A[j] > v){

			A[j+1] = A[j];
		
			j--;

			A[j+1] = v;
		}

		for(int i=0;i<n-1;i++){

			printf("%d ",A[i]);
			
		
		}
	
	printf("%d\n",A[n-1]);

	

	
	}		


	return 0;
}
