#include<stdio.h>

int main(void)
{
	int x,v,j,i;
	
	scanf("%d",&x);
	
	int a[x];
	
	for(i=0;i<x;i++){
		scanf("%d",&a[i]);
	}
	
	for(i=1;i<x;i++){
		for(j=0;j<x;j++){
			printf("%d",a[j]);
			if(j==x-1){
				printf("\n");
			}else{
				printf(" ");
			}
		}
		
		
		
		v = a[i];
		j=i-1;
		
		while(j >= 0 && a[j] > v){
			a[j+1] = a[j];
			j--;
			a[j+1]=v;
		}
		
	}
	
	for(j=0;j<x;j++){
			printf("%d",a[j]);
			if(j==x-1){
				printf("\n");
			}else{
				printf(" ");
			}
		}
	
	return 0;
}
