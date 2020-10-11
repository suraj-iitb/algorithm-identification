#include<stdio.h>
int main(){
	int i,j,N,A[100],flag,b,c=0;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	flag=1;
	while(flag){
		flag=0;
		for(j=N-1;j>=1;j--){
			if(A[j]<A[j-1]){
				b=A[j];
				A[j]=A[j-1];
				A[j-1]=b;
				flag=1;
				c++;
			}
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
