#include<stdio.h>

int main(void){
	int i,j,minj;
	int n,a[100];
	int tmp,cnt;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&(a[i]));
	}
	cnt=0;
	for(i=0;i<n;i++){
		minj=i;
		for(j=i;j<n;j++){
			if(a[j]<a[minj]){
				minj=j;
			}
		}
		if(i!=minj){
			tmp=a[i];
			a[i]=a[minj];
			a[minj]=tmp;
			cnt++;
		}
	}
	for(i=0;i<n;i++){
		printf("%d",a[i]);
		printf("%c",i==n-1?'\n':' ');
	}
	printf("%d\n",cnt);
	return 0;
}
