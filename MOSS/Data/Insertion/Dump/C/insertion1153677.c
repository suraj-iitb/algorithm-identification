#include <stdio.h>

int main(void)
{
	int i,j,k,n,key;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	
	printf("%d",a[0]);
	for(k=1;k<n;k++) printf(" %d",a[k]);
	printf("\n");
	
	for(i=1;i<n;i++){
		key=a[i];
		j=i-1;
		while(j>=0&&a[j]>key){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
		
		printf("%d",a[0]);
		for(k=1;k<n;k++) printf(" %d",a[k]);
		printf("\n");
		
	}
	
	return 0;
}
