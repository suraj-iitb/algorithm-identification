#include<math.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
int a[110],n,sw;
void swaping(int x,int y)
{
	int t;
	t=a[x];
	a[x]=a[y];
	a[y]=t;
	return;
}
void bubblesort()
{
	int i,j;
	for(i=1;i<=n-1;i++)
		for(j=n;j>=i+1;j--)
			if(a[j]<a[j-1])
			{
				swaping(j-1,j);
				sw++;
			}
	return;
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	bubblesort();
	for(i=1;i<=n-1;i++)
		printf("%d ",a[i]);
	printf("%d\n%d\n",a[n],sw);
	return 0;
}
