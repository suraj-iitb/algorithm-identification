#include <stdio.h>

int main(void) {
	// your code goes here
	int i,j,n,tmp,count=0;
	int a[1000];
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	
	for(i=0;i<n;i++){
		for(j=n-1;j>=i+1;j--){
			if(a[j]<a[j-1]){
				tmp=a[j];
				a[j]=a[j-1];
				a[j-1]=tmp;
				count++;
			}
		}
	}
	
	for(i=0;i<n-1;i++)printf("%d ",a[i]);
	printf("%d\n%d\n",a[n-1],count);
	return 0;
}

