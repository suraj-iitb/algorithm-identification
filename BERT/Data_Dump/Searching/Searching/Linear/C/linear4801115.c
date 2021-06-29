#include <stdio.h>
int main ()
{
	int n ,q, a,a1[10000],a2[100000],k = 0, i, j;
	scanf("%d",&n);
	for(i = 0;i < n; i++)
	{
		scanf("%d",&a1[i]);
	}
	scanf("%d",&q);
	for(int i = 0;i < q; i++)
	{
		scanf("%d",&a2[i]);
		for(j = 0;j < n; j++)
		{
			if(a1[j] == a2[i])
			 {
			 k++;
			 break;
			 }
		}
	}
	printf("%d\n",k);
	return 0;
}
