#include <stdio.h>
#define N 100

int main()
{
	int A[N], len, i, j, temp, cnt = 0;
	
	scanf("%d", &len);
	for(i = 0; i < len; i++)
	{
		scanf("%d", &A[i]);
	}
	
	for(i = 0; i < len - 1; i++)
	{
		for(j = len - 1; j > i; j--)
		{
			if(A[j] < A[j - 1])
			{
				temp = A[j - 1];
				A[j - 1] = A[j];
				A[j] = temp;
				cnt++;
			}
		}
	}
	
	for(i = 0; i < len; i++)
	{
		if(i == len - 1) printf("%d\n", A[i]);
		else printf("%d ", A[i]);
	}
	printf("%d\n", cnt);
	
	return 0;
}
