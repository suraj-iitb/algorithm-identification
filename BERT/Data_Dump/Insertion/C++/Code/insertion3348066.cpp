#include <stdio.h>

void disp(int a[],int n)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		if(i>0) printf(" ");
		printf("%d",a[i]);
	}
	printf("\n");
}
//插入排序法！
void sort(int a[],int n)
{
	int v,i,j;
	for(i=1;i<n;i++)
	{
		v=a[i];
		j=i-1;
		while(j>=0&&a[j]>v)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=v;
		disp(a,n);
	}
}

int main()
{
	int n,i;
	scanf("%d",&n);
	int a[101]={0};
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	disp(a,n);
	sort(a,n);
	return 0;
}
