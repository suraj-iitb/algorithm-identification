#include <stdio.h>

int main(void){
	int i,o,a[100]={0},p=0,min,temp,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	for(i=0;i<=n-1;i++){
		min=i;
		for(o=i+1;o<=n-1;o++){
			if(a[o]<a[min])
				min=o;
		}
		if(i != min)
			p++;
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}
	for(i=0;i<n;i++){
		printf("%d",a[i]);
		if(i != n-1)
			printf(" ");
	}
	printf("\n%d\n",p);
	return 0;
}
