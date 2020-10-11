#include <stdio.h>

void swap(int *,int *);
int main(void){
	int i,n;
	int count=0,flag;
	int a[100];
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	flag=1;
	while(flag){
		flag=0;
		for(i=n-1;i>0;i--){
			if(a[i]<a[i-1]){
				swap(&a[i],&a[i-1]);
				flag=1;
				count++;
			}
		}
	}
	
	for(i=0;i<n;i++){
		printf("%d",a[i]);
		if(i<n-1)
			printf(" ");
	}
	printf("\n");
	printf("%d\n",count);
	
	
	return 0;
}

void swap(int *px,int *py){
	int tmp=*px;
	*px=*py;
	*py=tmp;
}
