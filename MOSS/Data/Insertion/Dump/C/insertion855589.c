#include <stdio.h>

int main(void)
{
	int n, b[200];
	int i, j, k, key;
	
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
	}
	
	for(j=2;j<=n;j++)
	{
		for(k=1;k<n;k++)
		{
			printf("%d ", b[k]);
		}
		printf("%d\n", b[k]);
		
		key = b[j];
		i=j-1;
		while(i>0 && b[i]>key)
		{
			b[i+1] = b[i];
			i--;
		}
		b[i+1]=key;
}

for(k=1;k<n;k++)
{
	printf("%d ", b[k]);
}
printf("%d\n", b[k]);
	
	
	
	
	return 0;
}
