#include<stdio.h>
int main(){
	
	int i,j,flag=1,n,a[100],b,count=0;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	while(flag){
		flag=0;
		for(i=n-1;i>=0;i--){
			b=a[i];
			if(a[i]<a[i-1]){
				a[i]=a[i-1];
				a[i-1]=b;
				flag=1;
				count++;
			}
		}
	}
	for(i=0;i<n;i++){
		printf("%d",a[i]);
		if(i<n-1){
			printf(" ");
		}
	}
	puts("");
	printf("%d\n",count);
	return 0;
}
