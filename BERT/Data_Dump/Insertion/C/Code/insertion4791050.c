#include<stdio.h>


int main(){
	int N,i,v,j,k,A[1000];


	scanf("%d", &N);
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	
	
	for(i=0;i<N;i++){
		v = A[i];
		j = i - 1;
		while (j>=0 && A[j]>v){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;
		
		for(k=0;k<N;k++){
			
				if(k>0) printf(" ");
				printf("%d",A[k]);
							
		}
		printf("\n");	
}

	
return 0;	

} 

