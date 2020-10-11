#include<stdio.h>


int main(void){
	static int a[2000000],b[2000000],c[10001];
	int n;
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&(a[i]));
	}
	for(i=0;i<=10000;i++){
		c[i]=0;
	}
	for(i=0;i<n;i++){
		c[a[i]]++;
	}
	for(i=1;i<=10000;i++){
		c[i]=c[i]+c[i-1];
	}

	for(i=0;i<n;i++){
		b[c[a[i]]-1]=a[i];
		c[a[i]]--;
	}
	for(i=0;i<n;i++){
		printf("%d%c",b[i],i==n-1?'\n':' ');
	}
	return 0;
}
