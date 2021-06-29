#include<stdio.h>
int main() {
	int n,i,j,min,t=0,mid;
	scanf("%d",&n);
	int a[n+1];
	for(i=0; i<n; i++)
		scanf("%d",&a[i]);
	for(i=0; i<n; i++) {
		min=i;
		for(j=i; j<n; j++) {
			if(a[j]<a[min]) {
				min=j;
			}
		}
		if(min!=i) {
			mid=a[i];
			a[i]=a[min];
			a[min]=mid;
			t++;
		}
	}
	for(i=0; i<n; i++) {
		if(i>0)
			printf(" ");
		printf("%d",a[i]);
	}
	printf("\n%d\n",t);
	return 0;
}
