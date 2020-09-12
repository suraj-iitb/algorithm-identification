#include<cstdio>
#include<functional>
#include<algorithm>
using namespace std;
void func(int);

int main(void)
{
	int n,i,j,a[100],v;
	scanf("%d",&n);
	for(i=0;i<n;i++)	scanf("%d",&a[i]);
	printf("%d",a[0]);
	for(i=1;i<n;i++)	printf(" %d",a[i]);
	printf("\n");
	for(i=1;i<n;i++)	{
		v=a[i];
		j=i-1;
		while(j>=0 && a[j]>v)	{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=v;
		printf("%d",a[0]);
		for(j=1;j<n;j++)	printf(" %d",a[j]);
		printf("\n");
	}
	return 0;
}
