#include<stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i = 0; i < n; i++)scanf("%d",&arr[i]);
	printf("%d",arr[0]);
	for(int k = 1; k < n; k ++)printf(" %d",arr[k]);
	printf("\n");
	for(int i = 1; i < n; i++){
		int temp = arr[i];
		int j = i - 1;
		while(arr[j] > temp && j >= 0){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
		printf("%d",arr[0]);
		for(int k = 1; k < n; k ++)printf(" %d",arr[k]);
		printf("\n");
	}
	return 0;
}
