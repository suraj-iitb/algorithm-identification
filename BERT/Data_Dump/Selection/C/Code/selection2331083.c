#include <stdio.h>
int main(void)
{
	int A[100],N,i,j,minj,t,cou=0;
	
	scanf("%d",&N);
	
	for(i=0; i<N; i++){
		scanf("%d",&A[i]);
	}
	
	for(i=0; i<N-1; i++){
		minj=i;
		
		for(j=i; j<N; j++){
			if( A[j]<A[minj] ){
				minj=j;
			}
		}
			t=A[i];
			A[i]=A[minj];
			A[minj]=t;
			
			if(i != minj){cou++;}
			
			}
	
	for(i=0; i<N; i++){
			if(i>0){printf(" ");}
		printf("%d",A[i]);
	}
	printf("\n");
	printf("%d\n",cou);
	
	return 0;
}
