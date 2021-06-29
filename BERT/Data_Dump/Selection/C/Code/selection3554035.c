#include <stdio.h>

int main(void) {
	int n;
	int count = 0;
	scanf("%d",&n);
	int arr[n];
	for(int i = 0; i < n; i++)scanf("%d",&arr[i]);
	for(int i = 0; i < n-1; i++){
		int min = i;
		for(int j = i; j < n; j++){
			if(arr[min] > arr[j]){
				min = j;
			}
		}
		if(arr[i] > arr[min]){
			int temp = arr[i];
			arr[i]   = arr[min];
			arr[min]= temp;
			count++;
		}
	}
	printf("%d",arr[0]);
	for(int i = 1; i < n; i++)printf(" %d",arr[i]);
	printf("\n%d\n",count);
	return 0;
}
