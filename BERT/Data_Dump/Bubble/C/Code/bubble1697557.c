#include <stdio.h>
int main(){
	int i,j;
	int n;
	int a[100];
	int count=0;
	int flag=1;
	int tmp;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	
	for(i=1;i<n;i++){
		for(j=0;j<=n-i-1;j++){
			if(a[j]>a[j+1]){
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
				count++;
			}
		}
	}
	for(i=0;i<n-1;i++)printf("%d ",a[i]);
	printf("%d\n",a[i]);
	printf("%d\n",count);
return 0;
}
