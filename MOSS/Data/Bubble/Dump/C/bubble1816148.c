#include<stdio.h>

int main(void){
	int a[100];
	int n;
	int i,flag;
	int tmp,cnt;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&(a[i]));
	}
	flag=1;
	cnt=0;
	while(flag){
		flag=0;
		for(i=n-1;i>=1;i--){
			if(a[i]<a[i-1]){
				tmp=a[i];
				a[i]=a[i-1];
				a[i-1]=tmp;
				cnt++;
				flag=1;
			}
		}
	}
	for(i=0;i<n;i++){
		printf("%d",a[i]);
		printf("%c",i==n-1?'\n':' ');
	}
	
	printf("%d\n",cnt);
	return 0;

}
