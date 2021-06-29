#include <stdio.h>

int main()
{
	int n,a[100],memo,i,k;
	scanf("%d",&n);
	for(i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
		i<n-1? printf("%d ", a[i]):printf("%d\n", a[n-1]);
    }

	for (i = 1; i < n; ++i)
	{
		memo = a[i]; 
		k = i-1;
		while(k >= 0 && a[k] > memo)
		{
			a[k+1] = a[k];
			a[k] = memo;
			k--;
		}

		for (k = 0; k < n-1; ++k)
		{
			printf("%d ", a[k]);
		}
		printf("%d\n", a[n-1]);

	}

	return 0;
}
