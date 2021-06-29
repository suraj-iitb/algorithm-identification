#include<stdio.h>



int main(void){
	
	int N,i,j,z,v;
	int A[100];
	
	scanf("%d",&N);
	for(i=0; i<N; i++){
		scanf("%d",&A[i]);
	}
	
	for(i = 0; i<N; i++){
		if(i>0){
			printf(" ");
		}
		printf("%d",A[i]);
	}
	printf("\n");
	
	
	for(i = 1; i<N; i++){
		
		v = A[i];
		j = i - 1;
		while(j >= 0 && A[j] > v){
		
			A[j+1] = A[j];
			j--;
		}
		
		A[j+1]=v;
		
			
		for(z = 0; z<N; z++){
			if(z>0){
				printf(" ");
			}
			printf("%d",A[z]);
		}
	printf("\n");
	
	}

	return 0;

}
