#include<stdio.h>

int main(void)
{
	int i, j, v, N;
	int c;
	scanf("%d", &N);
	
	int A[N];
	for(i=0; i<N; i++){ scanf("%d", &A[i]); }
	for(c=0; c<N; c++)
	{
		if(c==N-1){ printf("%d\n", A[c]); }
		else{ printf("%d ", A[c]); }
	}
	for(i=1; i<N; i++)
	{
		v=A[i];
		j=i-1;
		while(j>=0 && A[j]>v)
		{
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=v;
		for(c=0; c<N; c++)
		{
			if(c==N-1){ printf("%d\n", A[c]); }
			else{ printf("%d ", A[c]); }
		}
	}
	
	return 0;
}
