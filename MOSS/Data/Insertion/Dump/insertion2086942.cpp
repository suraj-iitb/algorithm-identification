#include <cstdio>

int n;
int a[105];

int main(void){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		printf("%d%c",a[i],i==n-1?'\n':' ');
	}
	for(int i=1;i<=n-1;i++){
		int v=a[i];
		int j=i-1;
		while(j>=0 && a[j]>v){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=v;
		for(int k=0;k<n;k++){
			printf("%d%c",a[k],k==n-1?'\n':' ');
		}
	}
	return 0;
}
