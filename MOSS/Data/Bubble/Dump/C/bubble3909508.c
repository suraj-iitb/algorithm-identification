#include<stdio.h>

int main(void){
	int n;
	int a[100];
	int i, j,count,x;
	scanf("%d", &n);
	for(i = 0;i<n;i++){
		scanf("%d", &a[i]);
	}
	count =0;
	for(i = 0;i<n;i++){
		for(j = n-1;j>i;j--){
			if(a[j]<a[j-1]){
				x = a[j-1];
				a[j-1] = a[j];
				a[j] = x;
				count++;
			}
		}
	}
	for(i = 0;i<n-1;i++){
		
		printf("%d ", a[i]);
	}
	printf("%d\n", a[n-1]);
	printf("%d\n", count);
	
	return 0;


}



