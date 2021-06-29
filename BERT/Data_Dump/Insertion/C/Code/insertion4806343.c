#include <stdio.h>

int main(void) {
	// your code goes here
	int i,j,n,tmp;
	int a[1000];
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	
	for(i=0;i<n;i++){
		tmp=a[i];
		for(j=i;j>0;j--){
			if(tmp<a[j-1]){
				a[j]=a[j-1];
				if(j-1==0){
					a[j-1]=tmp;
					break;
				}
			}else{
				a[j]=tmp;
				break;
			}
		}
		for(j=0;j<n-1;j++)printf("%d ",a[j]);
		printf("%d\n",a[n-1]);
	}
	return 0;
}

