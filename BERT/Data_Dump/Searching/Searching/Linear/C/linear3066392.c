#include<stdio.h>

int sea(int a[],int n,int key);

int main(void){
	int i,n,a[10000+1],q,key,sum=0;
	
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d",&key);
		if(sea(a,n,key))sum++;
	}
	printf("%d\n",sum);
	
	return 0;
}

int sea(int a[],int n,int key){
	int i=0;
	a[n]=key;
	while(a[i]!=key)i++;
	
	return i!=n;
}
