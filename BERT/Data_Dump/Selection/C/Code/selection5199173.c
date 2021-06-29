#include <stdio.h>

int main(void){
	int n, a[100], minj;
	int i, j;
	int b = 0;

	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	for(i = 0; i < n; i++)
	{
		minj = i;
		for(j = i; j < n; j++)
		{
			if(a[j] < a[minj])
			{
				minj = j;
			}
		}
		if(i != minj)
		{
			int t = a[i];
			a[i] = a[minj];
			a[minj] = t;
			b++;
		}
	}
	for(i = 0; i < n; i++)
	{
		if(i == n - 1) printf("%d\n", a[i]);
		else printf("%d ", a[i]);
	}
	printf("%d\n", b);
}

