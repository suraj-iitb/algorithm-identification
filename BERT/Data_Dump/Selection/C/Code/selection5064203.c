#include<stdio.h>

int main(){
	int A[100],N,i,j,min,b,c=0;
	
	scanf("%d",&N);
	
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	
	for(i=0;i<N;i++){
		min=i;
		
		for(j=i;j<N;j++){
		    
			if(A[j]<A[min]){
				min=j;
			}
		}
		
		if(A[i]>A[min]){
			b=A[i];
			A[i]=A[min];
			A[min]=b;
			c++;
		}
	}
	
	for(i=0;i<N;i++){
	    
		if(i>0){
			printf(" ");
		}
		
		printf("%d",A[i]);
	}
	
	printf("\n");
	
	printf("%d\n",c);
	
	return 0;
}
