#include<stdio.h>

int main(void)
{
	int n , a[100], kari;
	
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
		printf("%d", a[i]);
		if(i != n-1){
			printf(" ");
		}
	}
	printf("\n");
	
	for(int i=1; i<n; i++){
		for(int j=i-1; j>=0; j--){
			if(a[j] > a[j+1]){
				kari = a[j];
				a[j] = a[j+1];
				a[j+1] = kari;
			}
		}
		for(int j=0; j<n; j++){
			printf("%d", a[j]);
			if(j == n-1){
				printf("\n");
			}else{
				printf(" ");
			}
		}
	}
	
	return 0;
}
