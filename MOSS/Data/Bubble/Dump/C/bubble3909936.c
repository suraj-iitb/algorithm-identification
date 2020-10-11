#include<stdio.h>
#include<stdlib.h>

void bubble(int *a,int n){
	int x,flag=1;
	int cnt=0;
	while(flag!=0){
		flag=0;
		for(int i=n-1;i>0;i--){
			if(a[i]<a[i-1]){
				x=a[i];
				a[i]=a[i-1];
				a[i-1]=x;
				flag=1;
				cnt++;
			}
		}
	}
	//出力
	for(int i=0;i<n;i++){
			printf("%d",a[i]);
			if(i!=n-1){
				printf(" ");
		}else{
			printf("\n");
		}
		
	}printf("%d\n",cnt);
}

int main(void){
	
	int n;
	int* a=(int*)malloc(sizeof(int)*n);
	
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	bubble(a,n);
	
}
