#include <stdio.h>
#include <string.h>
int main(void)
{
	int a[101];
	int n;
	int i,j;
	int temp,temp2;
	int x=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		
		scanf("%d",&a[i]);
		
	}
	for(i=0;i<n;i++){
		temp=i;
		for(j=i;j<n;j++){
			if(a[j]<a[temp]){
			temp=j;
			
			}
			}
			temp2=a[temp];
			a[temp]=a[i];
			a[i]=temp2;
			if(temp!=i){
				x++;
			}
		}
	
	for(i=0;i<n;i++){
		if(i==n-1){
			printf("%d\n",a[i]);
		}else{
		printf("%d ",a[i]);
		}
	}
	printf("%d\n",x);
	return 0;
}
