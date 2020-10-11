#include <stdio.h>

int main(void)
{
	int n,a[100],i,j,t,s=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	for(i=0;i<n-1;i++){
		for(j=n-1;j>i;j--){
			if(a[j-1]>a[j]){
				t=a[j-1];
				a[j-1]=a[j];
				a[j]=t;
				s++;
			}
		}
	}
	printf("%d",a[0]);
	for(i=1;i<n;i++)printf(" %d",a[i]);
	printf("\n%d\n",s);
	return 0;
}
