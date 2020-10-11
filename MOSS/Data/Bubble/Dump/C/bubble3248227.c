# include <stdio.h>
int main()
{
	int a[100];
	int n;
	int flag = 1;
	int num = 0;
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int j = 0;j<n-1&&flag==1;j++)
	{
		flag = 0;
		for(int i = 0; i<n-1-j;i++)
		{
			if(a[i]>a[i+1])
			{
				num++;
				int tem;
				tem = a[i];
				a[i] = a[i+1];
				a[i+1] =tem;
				flag = 1;
			}
		}
		
	}
	for(int i = 0;i<n-1;i++)
	printf("%d ",a[i]);
	printf("%d",a[n-1]);
	printf("\n%d\n",num);
	
}
