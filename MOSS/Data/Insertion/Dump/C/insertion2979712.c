#include <stdio.h>

int main(void)
{
	int n,a[100],i,j,t;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	for(i=0;i<n;i++){
		t=a[i];
		j=i-1;
		while(j>=0&&a[j]>t){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=t;
		for(j=0;j<n-1;j++)printf("%d ",a[j]);
		printf("%d\n",a[n-1]);
	}
	return 0;
}
