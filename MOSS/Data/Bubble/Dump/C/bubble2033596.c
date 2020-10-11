#include <stdio.h>
#include <stdlib.h>

int main(void){
	int o,flag=1,i=0,p=0,n,j,temp;
	scanf("%d",&n);
	int a[100]={0};
	for(o=0;o<n;o++)
		scanf("%d",&a[o]);

	while(flag){
		flag=0;
		for(j=n-1;j>=i+1;j--){
			if(a[j] < a[j-1]){
				temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
				flag=1;p++;
			}
		}i++;
	}
	for(o=0;o<n;o++){
		printf("%d",a[o]);
		if(o != n-1)
			printf(" ");
	}
	printf("\n%d\n",p);
	return 0;
}
