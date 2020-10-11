#include<stdio.h>

int main(void){
	int n;
	int a[100];
	int i,j;
	int box;
	int count=0;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i = 0;i < n-1;i++){
		for(j = 0;j < n-1-i;j++){
			if(a[j] > a[j+1]){
				box = a[j];
				a[j] = a[j+1];
				a[j+1] = box;
				count += 1;
			}
		}
	}
	
	for(i = 0;i < n;i++){
		if(i) printf(" ");
		printf("%d",a[i]);
	}
	
	printf("\n%d\n",count);
	return 0;
}
