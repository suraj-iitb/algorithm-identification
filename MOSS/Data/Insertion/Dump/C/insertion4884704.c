#include<stdio.h>
int main(){
	int N;
    int i,j,temp;
    
    scanf("%d", &N);
    
	int A[N];
	for( i=0; i<N; i++ ){
		scanf("%d",&A[i]);
	}
	for( i=0; i<N; i++ ){
		temp=A[i];
		j=i;
		while( j>0 && A[j-1]>temp ){
			A[j]=A[j-1];
			j--;
		}
		A[j]=temp;
		for(j=0; j<N; j++){
			printf("%d",A[j]);
			if(j+1!=N){
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
