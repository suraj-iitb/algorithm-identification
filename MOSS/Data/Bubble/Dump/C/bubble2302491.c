#include<stdio.h>


int main(){
	int n;
	int arr[100];
	int i;
	int a;
	int j, k;
	int count = 0;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	
	
	for(j=n-1; j>=0; j--){
		for(k=n-1; k>=0; k--){
			if(arr[k-1]>arr[k]){
				a = arr[k-1];
				arr[k-1] = arr[k];
				arr[k] = a;
				count++;
			}
		}
	}
	
	for(i=0; i<n; i++){
		if(i!=0 && i!=n){
			printf(" ");
		}
		printf("%d",arr[i]);
	}
	printf("\n");
	printf("%d\n",count);
	
	
	return 0;
}
