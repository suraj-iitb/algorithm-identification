//2016/11/3
//selection sort

#include <stdio.h>

int main(void)
{
	int i,j;
	int n,min,temp,count = 0,a[100] = {0};

	scanf("%d", &n);

	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	for(i = 0; i < n; i++)
	{
		min = i;

		for(j = i; j < n; j++)
		{
			if (a[min] > a[j])
			{
				min = j;
			}
		}

		if (i != min)
		{
			temp = a[i];
			a[i] = a[min];
			a[min] = temp;

			count++;
		}

	}

	for(i = 0; i < n; i++)
	{
		if (i == n-1)
		{
			printf("%d\n", a[i]);
			printf("%d\n", count);
		}else
		{
			printf("%d ", a[i]);
		}
	}



	return 0;
}
