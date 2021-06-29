#include<stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);
	int A[N];
	int i, j, k;
	int v;

	for(i=0; i<N; i++)//配列の表示
	{
		scanf("%d", &A[i]);
		if(i < N-1)
		{
			printf("%d ", A[i]);
		}
		else
		{
			printf("%d\n", A[i]);
		}
	}

	for(i=1; i<=N-1; i++)
	{
		v = A[i];
		j = i-1;
		while(j >=0 && A[j] > v)// 挿入ソート
		{
			A[j+1] = A[j];
			j--;
			A[j+1] = v;
		}
		for(k=0; k<N; k++)//配列の表示
		{
			if(k < N-1)
			{
				printf("%d ", A[k]);
			}
			else
			{
				printf("%d\n", A[k]);
			}
		}

	}
	return 0;
}

