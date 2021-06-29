#include <stdio.h>

int main()
{
	int n,i,j,key,t;
	int a[100];
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	for(t=0;t<n-1;t++)
	printf("%d ",a[t]);
	printf("%d",a[n-1]);
	putchar('\n');
	for(i=1;i<n;i++)
	{
		key = a[i];
		for(j=i;j>0;j--){
		if(key<a[j-1]) {a[j] = a[j-1];a[j-1] = key;}
		}
		for(t=0;t<n-1;t++)
		printf("%d ",a[t]);
		printf("%d",a[n-1]);
		putchar('\n');
	}
	return 0;
}
