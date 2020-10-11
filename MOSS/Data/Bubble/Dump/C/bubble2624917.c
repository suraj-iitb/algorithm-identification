#include<stdio.h>
int main()
{	int i,j,x;
	int N;
	int count=0;

	scanf("%d",&N);
	int A[N];
	for (i = 0; i < N; i++)
	{
		scanf("%d",&A[i]);
	}
	for(i=0;i<N;i++){
		for(j=N-1;j>=i+1;j--){
			if(A[j]<A[j-1]){
				x=A[j];
				A[j]=A[j-1];
				A[j-1]=x;
				count++;
			}
		}
	}

	for(i=0;i<N-1;i++){
		printf("%d",A[i]);
		printf(" ");
		}
		printf("%d\n",A[i]);
	printf("%d\n",count);
	return 0;
}
