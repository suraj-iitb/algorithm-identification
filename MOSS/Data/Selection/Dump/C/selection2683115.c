#include <stdio.h>

int a[105], n;

int main()
{
	scanf("%d", &n);
	int i, cnt;
	int selection_sort();
	for(i = 0; i < n; i++)
	{
		scanf("%d", a + i);
	}
	cnt = selection_sort();
	for(i = 0; i < n; i++)
	{
		if(i > 0)
		{
			printf(" ");
		}
		printf("%d", a[i]);
	}
	printf("\n%d\n", cnt);
	
	return 0;
}

int selection_sort()
{
	int i, j, cnt, flag;
	for(i = 0; i < n - 1; i++)
	{
		flag = i;
		for(j = i + 1; j < n; j++)
		{
			if(a[flag] > a[j])
			{
				flag = j;
			}
		}
		if(flag != i)
		{
			int tmp = a[i];
			a[i] = a[flag];
			a[flag] = tmp;
			cnt++;
		}
	}
	
	return cnt;
}
