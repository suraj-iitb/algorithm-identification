#include<stdio.h>
int main(){
	int n,i,j,k;
	scanf("%d",&n);
	int a[100]; 
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	if(i<n-1)printf("%d ",a[i]);	
	}
	printf("%d\n",a[i-1]);
	
	for(i=1;i<n;i++){
		
		int v=a[i];
		j=i-1;
		while(j>=0&&a[j]>v){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=v;
		for(k=0;k<n-1;k++){
			printf("%d ",a[k]);
		}
		printf("%d\n",a[k]);
	}
	return 0;
}
