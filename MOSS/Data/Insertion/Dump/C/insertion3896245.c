#include <stdio.h>

int main(void)
{
	int n,i,j,k,v,a[100];
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<n;i++){
		v= a[i];
		j=i-1;
		while(j>=0 && a[j]>v){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=v;	
		
		for(k=0;k<n;k++){
			if(k>0){
				printf(" ");
			}
			
			printf("%d",a[k]);
			
			if(k==n-1){
				printf("\n");
			}
		}
	}
	return 0;
}
