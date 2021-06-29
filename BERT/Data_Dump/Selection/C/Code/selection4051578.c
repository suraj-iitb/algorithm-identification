#include <stdio.h>
int main(){
	int i,j,minj,count=0,A[100],N,a;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	for(i=0;i<N-1;i++){
		minj=i;
		for(j=i+1;j<N;j++){
			if(A[j]<A[minj])
				minj=j;	
		}
		if(A[i]>A[minj]){
		a=A[i];
		A[i]=A[minj];
		A[minj]=a;
		count++;
	}
	}
	for(i=0;i<N;i++){
		printf("%d",A[i]);
		if(i<N-1)
			printf(" ");
	}
	printf("\n%d\n",count);
	return 0;
}
