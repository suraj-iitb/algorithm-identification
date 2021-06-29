#include<stdio.h>
int main(void){
	int i,count=0,flag,N,A[100],MI;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	
	flag=1;
	i=0;
	while(flag){
		flag=0;
		for(int j=N-1;j>i;j--){
			if(A[j]<A[j-1]){
				MI=A[j];
				A[j]=A[j-1];
				A[j-1]=MI;
				flag=1;
				count++;
			}
		}
	}
	
	for(i=0;i<N;i++){
		printf("%d",A[i]);
		if(i!=N-1){
			printf(" ");
		}
	}
	printf("\n%d\n",count);
	return 0;
}
