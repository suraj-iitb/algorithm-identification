#include <stdio.h>

void selection(int *arr, int size){
	int count = 0;
	int min = 0;
	for(int i=0; i< size;i++){
		min = i;
		for(int j=i; j<size; j++){
			if(arr[j] < arr[min]){
				min = j;
				
			}
		}
		if(i != min) count++;
		int tmp = arr[i];
		arr[i] = arr[min];
		arr[min] = tmp;
		
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
	selection(num, size);
	return 0;
}
