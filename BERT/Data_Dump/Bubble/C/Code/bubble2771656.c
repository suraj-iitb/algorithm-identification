#include<stdio.h>
void swap(int* a,int* b){
	int p;
	p=*a;
	*a=*b;
	*b=p;
}
int main(){
	int n,a[100],count=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++){
		for(int j=n-1;j>i;j--){
			if(a[j]<a[j-1]){
				swap(&a[j],&a[j-1]);
				count++;
				}
		}
	}
	for(int i=0;i<n;i++)
		printf("%d%s",a[i],i!=n-1?" ":"\n");
	printf("%d\n",count);
	return 0;
}
