#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include <math.h>
int main(void){
	int a[101],b,n,i,j,k;
	scanf("%d%*c",&n );
	for(i=0;i<n;i++){
		scanf("%d",&a[i] );
	}
	for(k=0;k<n;k++){
		if(k==n-1){
			printf("%d\n",a[k] );
			break;
		}
		printf("%d ",a[k] );
	}
	for(i=1;i<n;i++){
		b=a[i];
		j=i-1;
		while(j>=0 && a[j]>b){
			a[j+1]=a[j];
			j--;
			a[j+1]=b;
		}
		for(k=0;k<n;k++){
			if(k==n-1){
				printf("%d\n",a[k] );
				break;
			}
			printf("%d ",a[k] );
		}
	}
	return 0;
}
