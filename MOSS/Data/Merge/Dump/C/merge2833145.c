#include <stdio.h>
#include <limits.h>
int count = 0;
void merge(int *array, int p, int q, int r){
	int n1 = q-p+1;
	int n2 = r-q;

	int left[n1 + 1];
	int right[n2 + 1];

	for(int i = 0; i < n1; ++i){
		left[i] = array[p + i];
	}
	left[n1] = INT_MAX;
	for(int i = 0; i < n2; ++i){
		right[i] = array[q + 1 + i];
	}
	right[n2] = INT_MAX;

	int i=0, j=0;
	for(int k = p; k <= r; ++k){
		++count;
		if(left[i] < right[j]){
			array[k] = left[i];
			++i;
		}else{
			array[k] = right[j];
			++j;
		}
	}
}
void mergeSort(int *array, int p, int r){
	if(p < r){
		int q = (p+r)/2;
		mergeSort(array, p, q);
		mergeSort(array, q+1, r);
		merge(array, p, q, r);
	}
}

void printarray(int array[], int size){
	for(int i = 0; i < size; ++i){
		printf("%d", array[i]);
		if(i != size - 1)
			printf(" ");
	}
	printf("\n");
}
int main(){
	int n;
	scanf("%d", &n);
	int numbers[n];
	for(int i = 0; i < n; ++i){
		scanf("%d", &numbers[i]);
	}	
	mergeSort(numbers, 0, n-1);
	printarray(numbers, n);
	printf("%d\n", count);
	return 0;
}
