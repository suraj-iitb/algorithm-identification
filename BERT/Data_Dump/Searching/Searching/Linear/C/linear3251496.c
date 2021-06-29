# include <stdio.h>
int main()
{
	int a[10000];
	int q;
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n; i++)
		scanf("%d",&a[i]);
	scanf("%d",&q);
	int num = 0;
	for(int i = 0; i < q; i++)
	{
		int ccc;
		scanf("%d", &ccc);
		a[n] = ccc;
		int j = 0;
		while(a[j] != ccc)
			j++;
		if(j != n)	num++;
	}
	printf("%d\n",num);
 } 
