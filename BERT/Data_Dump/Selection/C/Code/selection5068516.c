#include <stdio.h>
#define N 100

int main()
{
	int A[N], len, i, j, minj, temp, cnt = 0;
	int a;
	
	scanf("%d", &len);
	for(i = 0; i <= len - 1; i++)
	{
		scanf("%d", &A[i]);
	}
	
	for(i = 0; i < len - 1; i++)
	{
		minj = i;
		for(j = i + 1; j < len; j++)
		{
			if(A[j] < A[minj])
			{
				minj = j;
			}
		}
		if(A[i] != A[minj]) cnt++;
		temp = A[i];
		A[i] = A[minj];
		A[minj] = temp;
	}
	
	for(i = 0; i < len; i++)
	{
		if(i < len - 1) printf("%d ", A[i]);
		else printf("%d\n", A[i]);
	}
	printf("%d\n", cnt);
	
	return 0;
}
