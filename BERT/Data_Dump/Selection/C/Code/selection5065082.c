#include <stdio.h>

int main(void)
{
	int a[100],n,i,j,min,tmp,c=0;
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)scanf("%d",&a[i]);
	for(i=0;i<=n-1;i++){
		min=i;
		for(j=i;j<=n-1;j++)if(a[min]>a[j])min=j;
		if(a[i]!=a[min])c++;
		tmp=a[i];
		a[i]=a[min];
		a[min]=tmp;
	}
	for(i=0;i<n-1;i++)printf("%d ",a[i]);
	printf("%d\n%d\n",a[n-1],c);
	return 0;
}

