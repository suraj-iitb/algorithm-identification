#include<stdio.h>

int main()
{	int j,k;
	int N;
	int i=0;
	long v;

	scanf("%d",&N);
	long A[N];
	for (i = 0; i < N; ++i)
	{
		scanf("%ld",&A[i]);
	}
		for(i=0;i<N-1;i++){
		printf("%ld",A[i]);
		printf(" ");
		}
		printf("%ld\n",A[i]);	

	for(i=1;i<N;i++){
		v=A[i];
		j=i-1;
		while(j >= 0 && A[j]>v){
			A[j+1]=A[j];
			j--;}
			A[j+1]=v;
		for(k=0;k<N-1;k++){
		printf("%ld",A[k]);
		printf(" ");
		}
	printf("%ld\n",A[k]);
	}

	return 0;
}
