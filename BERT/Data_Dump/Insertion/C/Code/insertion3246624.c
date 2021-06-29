#include <stdio.h>
#include <limits.h>

void insertionSort(int *arr, int size){
	int j = 0;
	for(int i=1; i<size; i++){
		for(int k=0; k<size; k++){
			if(k!=size-1){
				printf("%d ", arr[k]);
			}
			else if(k==size-1){
				printf("%d\n", arr[k]);
			}
		}

		int v = arr[i];
		j = i-1;
		while(j>=0 && arr[j]>v){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = v;
	}
	for(int k=0; k<size; k++){
			if(k!=size-1){
				printf("%d ", arr[k]);
			}
			else if(k==size-1){
				printf("%d\n", arr[k]);
			}
		}
}

int main(){
	int size = 0;
	scanf("%d", &size);
	int num[size];
	for(int i = 0; i<size; i++){
		scanf("%d", &num[i]);
	}
	insertionSort(num, size);
	return 0;
}


