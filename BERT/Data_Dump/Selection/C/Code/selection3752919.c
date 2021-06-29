/*
*/

#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int a[100],i,j,minj,temp,sum=0;
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	for(i=0;i<n;i++){
		minj=i;
		for(j=i;j<n;j++){
			if(a[j]<a[minj])minj=j;	
		}
		if(minj!=i){
		
		temp=a[i];
		a[i]=a[minj];
		a[minj]=temp;
		sum++;
		}
	}
	for(i=0;i<n-1;i++){
		printf("%d ",a[i]);
	}
	printf("%d\n",a[i]);
	printf("%d\n",sum);
	}
