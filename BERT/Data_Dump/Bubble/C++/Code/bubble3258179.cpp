#include<bits/stdc++.h>
using namespace std;
int n,a[105],i,j,sw;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(i=1;i<=n-1;i++)
	for(j=n;j>=i+1;j--)
	{
		if(a[j]<a[j-1])
		{
			swap(a[j],a[j-1]);
			sw++;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(i>1)printf(" ");
		printf("%d",a[i]);
	}
	printf("\n");
	printf("%d\n",sw);
	return 0;
}
