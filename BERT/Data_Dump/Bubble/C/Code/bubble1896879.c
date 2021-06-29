#include<stdio.h>
int bsort(int a[],int n){
	int i,j,num=0;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(a[j+1]<a[j]){
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				num++;
			}
		}
	}
	return num;
}
int main(void){
	int i,n,num,x[100];
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&x[i]);}
	num=bsort(x,n);
	printf("%d",x[0]);
	for (i=1;i<n;i++){printf(" %d",x[i]);}
	printf("\n%d\n",num);
	return 0;
}
