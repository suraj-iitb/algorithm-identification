//?????????????????¶??????????????????

#include <stdio.h>

int main()
{
	int n,a[100],count=0,i,k,memo;
	scanf("%d",&n);
	for(i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
    }

	for (i = 0; i < n; ++i)
	{
		for (k = n-1; k > i; --k)
		{
			if(a[k]<a[k-1]){memo=a[k];a[k]=a[k-1];a[k-1]=memo;count++;}
		}
	}

	for (i = 0; i < n-1; ++i)
	{
			printf("%d ", a[i]);
	}
	printf("%d\n%d\n", a[n-1], count);
	
	return 0;
}
