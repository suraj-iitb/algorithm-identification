#include <stdio.h>
int main(void)
{
	int N;
	scanf("%d",&N);
	int A[100],i,j,tmp,k=0;
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	for(j=N-1;j>0;j--){
		for(i=0;i<j;i++){
			if(A[i]>A[i+1]){
				tmp=A[i];
				A[i]=A[i+1];
				A[i+1]=tmp;
				k++;
			}
		}
	}
	for(i=0;i<N;i++){
		if(i>=1) printf(" ");
		printf("%d",A[i]);
	}
	putchar('\n');
	printf("%d\n",k);
	return 0;
}
