#include<stdio.h>
#include<stdlib.h>

void ssort(int* a,int n){
	
	int minj,x,flag=0,cnt=0;
	
	for(int i=0;i<n;i++){
		minj=i;
		for(int j=i;j<n;j++){
			if(a[j]<a[minj]){
				minj=j;
				flag=1;
			}
		}
		x=a[i];
		a[i]=a[minj];
		a[minj]=x;
		if(flag==1)cnt++;
		flag=0;
	}
	for(int i=0;i<n;i++){
		printf("%d",a[i]);
		if(i!=n-1) printf(" ");
	}
	printf("\n");
	printf("%d\n",cnt);
}

int main(void){
	
	int n;
	int* a=(int*)malloc(sizeof(int)*n);
	
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	ssort(a,n);
	
}
