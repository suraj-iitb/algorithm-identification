#include<bits/stdc++.h>
using namespace std;
int n,a[105];
void pr()
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(i>1)printf(" ");
		printf("%d",a[i]);
	}
	printf("\n");
}
void sor()
{
	int i,j,k;
	for(i=2;i<=n;i++)
	{
		k=a[i];
		j=i-1;
		while(j>=1&&a[j]>k)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=k;
		pr();
	}
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	pr();
	sor();
	return 0;
}
