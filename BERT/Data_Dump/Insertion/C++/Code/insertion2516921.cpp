#include<cstdio>

int main(void){
	
	int i,n;
	
	scanf ("%d",&n);
	int a[n];
	
	for (i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	for (i=0;i<n-1;i++){
		printf("%d ",a[i]);
	}
	printf("%d\n",a[n-1]);
	
	for (i=1;i<n;i++){
		int v=a[i];
		int j=i-1;
		while ((j>=0) && v<a[j]){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=v;
		for(int k=0;k<n-1;k++){
			printf("%d ",a[k]);
		}
		printf("%d\n",a[n-1]);
	}
	
	return 0;
}
