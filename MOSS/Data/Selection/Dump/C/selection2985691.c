#include <stdio.h>

int main(void)
{
	int a[100],n,i,j,m,t,s=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	for(i=0;i<n;i++){
		m=i;
		for(j=i;j<n;j++)if(a[m]>a[j])m=j;
		if(a[i]!=a[m])s++;
		t=a[i];
		a[i]=a[m];
		a[m]=t;
	}
	for(i=0;i<n-1;i++)printf("%d ",a[i]);
	printf("%d\n%d\n",a[n-1],s);
	return 0;
}
