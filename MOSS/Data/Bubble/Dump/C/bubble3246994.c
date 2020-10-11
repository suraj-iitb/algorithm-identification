#include<stdio.h>
int main(void){
	int N,i,j,c,count=0;
	int flag=1;
	scanf("%d",&N);
	int A[N];
	for(i=0;i<N;i++){
		scanf("%d",A+i);
	}
	while(flag){
		flag = 0;
		for(j=N-1;j>0;j--){
			if(A[j]<A[j-1]){
				count++;
				c = A[j];
				A[j] = A[j-1];
				A[j-1] = c;
				flag = 1;
			}
		}
	}
	for(i=0;i<N-1;i++){
			printf("%d ",A[i]);
		}
		printf("%d",A[N-1]);
		printf("\n");
		printf("%d\n",count);
	return 0;
}
