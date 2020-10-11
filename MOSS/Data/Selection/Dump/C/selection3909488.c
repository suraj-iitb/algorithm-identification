#include<stdio.h>

int main(void){
	
	int n,i,max,min,tmp,j;
	int count=0;
	scanf("%d",&n);
	int a[100];
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i+1;j<n;j++){
			  if(a[j]<a[min]){
				min=j;	
			   }  
		
		}
		if(a[i]>a[min]){
		tmp=a[i];
		a[i]=a[min];
		a[min]=tmp;
			count++;
		}
	}
	
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
		if(i!=n-1){printf(" ");}
	}
	printf("\n");
	printf("%d\n",count);
	return 0;
}
