#include<cstdio>
#include<cmath>
int main(void){
	
	int i,j,n,c=0,b;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1;j++){
			if(a[j]>a[j+1]){
				c++;
				b=a[j];
				a[j]=a[j+1];
				a[j+1]=b;
			}
		}
	}

	for(i=0;i<n-1;i++){
		printf("%d ",a[i]);
	}
	printf("%d\n",a[n-1]);
	printf("%d\n",c);
	return 0;
}
