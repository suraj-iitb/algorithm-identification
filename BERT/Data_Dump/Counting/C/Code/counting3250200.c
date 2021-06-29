#include<stdio.h>
#include<stdlib.h>
#define m 2000001
#define vm 10000

int main(){
	unsigned short *a,*b;
	
	int c[vm+ 1];
	int n,i,j;
	scanf("%d",&n);
	
	a=malloc(sizeof(short)*n +1);
	b=malloc(sizeof(short)*n +1);
	
	for(i=0;i<=vm;i++)c[i]=0;
	
	for(i=0;i<n;i++){
		scanf("%hu",&a[i+1]);
		c[a[i+1]]++;
	}
	
	for(i=1;i<=vm;i++)c[i]=c[i]+c[i-1];
	
	for(j=1;j<=n;j++){
		b[c[a[j]]]=a[j];
		c[a[j]]--;
	}
	
	for(i=1;i<=n;i++){
		if(i>1)printf(" ");
		printf("%d",b[i]);
	}
	printf("\n");
	
	return 0;
}
