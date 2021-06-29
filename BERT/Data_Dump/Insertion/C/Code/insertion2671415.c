
#include <stdio.h>
#define N 100

int main(void)
{
	int i,j,n,a[N],temp;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		temp = a[i];
		for(j=i-1;j>=0 && a[j]>temp;j--)
			a[j+1] = a[j];
		a[j+1] = temp;
		printf("%d",a[0]);
		for(j=1;j<n;j++)
			printf(" %d",a[j]);
		printf("\n");
	}
	return 0;
}

