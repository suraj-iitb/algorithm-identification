#include <stdio.h>

int main(void) {
	// your code goes here
	int i,j,n,minj,tmp,count=0;
	int a[1000];
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	
	for(i=0;i<n-1;i++){
		minj=i;
		for(j=i+1;j<n;j++){
			if(a[j]<a[minj])minj=j;
		}
		tmp=a[i];
		a[i]=a[minj];
		a[minj]=tmp;
		if(i!=minj)count++;
	}
	for(i=0;i<n-1;i++)printf("%d ",a[i]);
	printf("%d\n%d\n",a[n-1],count);
	return 0;
}

