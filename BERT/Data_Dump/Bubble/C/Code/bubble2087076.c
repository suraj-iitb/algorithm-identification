#include<stdio.h>
int main(void){
	int n,i,j,v,flag,temp,cnt;
	int a[100];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	cnt=0;
	flag=1;
	while(flag){
		flag=0;
		for(j=n-1;j!=0;j--){
			if(a[j]<a[j-1]){
				temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
				cnt++;
				flag=1;
			}
		}
	}
	for(i=0;i<n-1;i++){
		printf("%d ",a[i]);
	}
	printf("%d\n",a[n-1]);
	printf("%d\n",cnt);
	return 0;
}
