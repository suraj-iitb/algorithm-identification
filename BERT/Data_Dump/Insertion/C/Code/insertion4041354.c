#include <stdio.h>
int main(){
	int i,j,A[100],key,N,t;
	scanf("%d",&N);
	for(i=0;i<N;i++)
		scanf("%d",&A[i]);
	for(i=0;i<N;i++){
		key=A[i];
		j=i-1;
		while(j>=0&&A[j]>key){
			A[j+1]=A[j];
			j--;
			A[j+1]=key;
		}
		for(t=0;t<N;t++){
			printf("%d",A[t]);
			if(t<N-1)
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}

