#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(void)
{
	int i,j;
	int N,a[100] = {0},v;

	scanf("%d", &N);
	for(i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}

	for(i = 0; i < N; i++)
	{
		v = a[i];
		for(j = i; j >= 0 && a[j-1] > v; j--)
		{
			a[j] = a[j-1];
		}
		a[j] = v;

		for(j = 0; j < N; j++)
		{
			if (j == N-1)
			{
				printf("%d\n", a[j]);
			}else
			{
				printf("%d ", a[j]);
			}
		}

	}


	return 0;
}
