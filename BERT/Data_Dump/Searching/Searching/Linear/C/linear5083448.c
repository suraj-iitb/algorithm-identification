#include <stdio.h>
int main ()
{
	int n ,x, y,a[10000],b[100000],z=0;
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	scanf("%d",&x);
	
	for(int i=0;i<x;i++){
		scanf("%d",&b[i]);
		for(int j=0;j<n;j++){
			if(a[j]==b[i]){
			 z++;
			 break;
			 }
		}
	}
	
	printf("%d\n",z);
	
	return 0;
	
}

