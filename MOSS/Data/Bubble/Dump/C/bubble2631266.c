#include<stdio.h>

int main(void){
	int N;
	int i;
	int A[100];
	scanf("%d", &N);
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}

	int flag = 1;
	int j;
	int tmp;
	int count=0;
	while (flag){
		flag = 0;
		for(j=N-1;j>0;j--){
			if(A[j]<A[j-1]){
				tmp = A[j];
				A[j] = A[j-1];
				A[j-1] = tmp;
				flag=1;
				count++;
			}
		}
	}
	for(j=0;j<N;j++){
		if(j==N-1){
			printf("%d\n",A[j]);
		}else{
			printf("%d ",A[j]);
		}
	}
	printf("%d\n", count);


	return 0;

}
