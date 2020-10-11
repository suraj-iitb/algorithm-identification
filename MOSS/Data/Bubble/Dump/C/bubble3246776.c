#include <stdio.h>

void bubble(int *arr, int size){
	int count = 0;
	for(int i=0; i< size;i++){
		for(int j = size-1; j>i; j--){
			if(arr[j] < arr[j-1]){
				int tmp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = tmp;
				count++;
			}
		}
	}
	for(int k=0; k<size; k++){
		if(k!=size-1){
			printf("%d ", arr[k]);
		}
		else if(k==size-1){
			printf("%d\n", arr[k]);
		}
	}
	printf("%d\n", count);
}

int main(){
	int size=0;
	scanf("%d", &size);
	int num[size];
	for(int i=0;i<size; i++){
		scanf("%d", &num[i]);
	}
	bubble(num, size);
	return 0;
}
