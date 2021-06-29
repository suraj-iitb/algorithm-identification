#include <stdio.h>

int * selectionSort(int * arr, int m, int* c){
	for(int i = 0; i < m; i++){
		int min = i;
		for(int j = i; j < m; j++){
			if(arr[j] < arr[min]){
				min = j;
			}
		}
		if(min != i){
			*c = *c + 1;
			int temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
	return arr;
}

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	int count = 0;
	int *b;
	b = selectionSort(a, n, &count);
	for(int i = 0; i < n; i++){
		if(i == n-1){
			printf("%d\n", b[i]);
		} else {
			printf("%d ", b[i]);
		}
	}
	printf("%d\n", count);
	return 0;
}

