#include <iostream>
using namespace std;
int main(){
	int i,j,temp;
	int n;
	int cnt=0;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n-1;++i){
		for(j=0;j<=n-1-i;++j){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				cnt++;
			}
		}
	}
	for(i=0;i<n;++i){
		printf("%d",a[i]);
		if(i!=n-1)
		printf(" ");
		if(i==n-1)
		printf("\n");
	}
	printf("%d\n",cnt);
	return 0;
}
