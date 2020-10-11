//2016/11/2

#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(void)
{
	int i;
	int n, a[101] = {0}, flag = 1, count = 0, temp;

	scanf("%d", &n);

	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	while(flag)
	{
		flag = 0;

		for(i = n-1; i > 0; i--)
		{
			if (a[i] < a[i-1])
			{
				temp = a[i];
				a[i] = a[i-1];
				a[i-1] = temp;
				flag = 1;
				count++;
			}
		}
	}

	for(i = 0; i < n; i++)
	{
		if (i == n-1)
		{
			printf("%d\n", a[i]);
		}else
		{
			printf("%d ", a[i]);
		}
	}

	printf("%d\n", count);

	return 0;
}
