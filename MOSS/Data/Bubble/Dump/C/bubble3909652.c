#include<stdio.h>
int bs(int a[],int n){
	int flag = 1,j = 0,l,i,c = 0;;
	for(i = 0;flag;i++){
		flag =0;
		for(j = n-1;j >=1;j--){
			if(a[j] < a[j-1]){
				l = a[j];
				a[j] = a[j-1];
				a[j - 1] = l;
				flag = 1;
				c++;
			}
			
		}
	}
	return c;
}
int main(void){

	int n,i,c;
	scanf("%d",&n);
	int a[n];
	
	for(i = 0;i < n;i++){
		scanf("%d",&a[i]);
	}
	c = bs(a,n);
	
	for(i = 0;i < n-1; i++){
		printf("%d ",a[i]);
	}
	printf("%d\n",a[n-1]);
	printf("%d\n",c);
}

