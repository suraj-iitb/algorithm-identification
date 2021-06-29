#include<stdio.h>
#define N 1000

int main(void){
	int set;
	int i,j,k;
	int a[N];
	int v;
	scanf("%d", &set);
	for(i=0;i<set;i++){
		scanf("%d", &a[i]);
		if(i!=set-1){
			printf("%d ",a[i]);
		}else if(i==set-1){
			printf("%d\n", a[i]);
		}
	}

	for(i=1;i<set;i++){
		v=a[i];
		j=i-1;
		while(j>=0 && a[j]>v){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=v;
		for(k=0;k<set;k++){
			if(k!=set-1){
				printf("%d ",a[k]);
			}else{
				printf("%d\n",a[k]);
			}
		}
	}
	return 0;
}
