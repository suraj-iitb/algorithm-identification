#include <stdio.h>

int main(void){

	int n,i,j,k,flag,a[100];
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	flag=0;
	
	for(i=0;i<n;i++){
		for(j=n-1;j>0;j--){
			if(a[j]<a[j-1]){
				k=a[j];
				a[j]=a[j-1];
				a[j-1]=k;
				flag++;
			}
		}
	}
	
	for(i=0;i<n;i++){
		if(i>0){
			printf(" ");
		}
		printf("%d",a[i]);
		if(i==n-1){
			printf("\n%d\n",flag);
			
		}
	}
	
	return 0;
}
