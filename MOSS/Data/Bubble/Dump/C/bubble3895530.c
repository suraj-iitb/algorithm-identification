#include<stdio.h>

int main(void){
	
	int n,i,maxv,minv,tmp,j;
	int count=0;
	scanf("%d",&n);
	int a[100];
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<n;i++)
	{
		for(j=n-1;j>i;j--){
			  if(a[j]<a[j-1]){
				tmp=a[j-1];
				a[j-1]=a[j];
				a[j]=tmp;
				
				count++;
			}
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
