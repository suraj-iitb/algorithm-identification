#include <stdio.h>

int main(void){
	int i,j,tmp;
	int N,flag=1,count=0;
	int A[100];

	//input
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}

	//bubble sort
	while(flag){
		flag = 0;
		for(j=N-1;j>0;j--){
			if(A[j]<A[j-1]){
				tmp = A[j];
				A[j]=A[j-1];
				A[j-1]=tmp;
				flag = 1;
				count++;
			}
		}
	}

	//output
	for(i=0;i<N;i++){
		printf("%d",A[i]);
		if(i<N-1) printf(" ");
	}
	printf("\n");
	printf("%d\n",count);

return 0;

}
