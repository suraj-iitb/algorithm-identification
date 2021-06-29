#include<stdio.h>
int sl(int a[],int n){
	int i,min,j,s,c = 0;
	for(i = 0;i < n;i++){
		min = i;
		for(j = i;j < n;j++){
			if(a[j]<a[min]){
				min = j;
			}
			
		}
		if(a[i]!=a[min]){
			
			s = a[i];
			a[i] = a[min];
			a[min] = s;
			c++;
		}
		
	}
	return c;


}
int main (void){
	
	int n,i,c;
	scanf("%d",&n);
	int a[n];
	
	for(i = 0;i < n;i++){
		scanf("%d",&a[i]);
	}
	c = sl(a,n);
	
	for(i = 0;i < n-1; i++){
		printf("%d ",a[i]);
	}
	printf("%d\n",a[n-1]);
	printf("%d\n",c);
	
}
