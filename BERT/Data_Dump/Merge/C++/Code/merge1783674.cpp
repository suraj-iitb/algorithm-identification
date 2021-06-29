#include <stdlib.h>
#include <iostream>
#include <climits>
using namespace std;

int merge_sort(int *array, int left, int right);
int merge(int *array, int left, int mid, int right);
void print_array(int *array, int size);
int main(){
	int n;

	cin >> n;

	int* array = (int*)malloc(n * sizeof(int));
	int result = 0;

	if(n < 1){
		return 0;
	}

	for(int i = 0; i < n; i++){
		cin >> array[i];
	}

	result = merge_sort(array, 0, n);
	print_array(array, n);
	cout << result <<endl;
	return 0;
}

int merge_sort(int *array, int left, int right){
	int swap_num = 0;
	if(left+1 < right){
		int mid = (left + right) >> 1;
		swap_num += merge_sort(array, mid, right);
		swap_num += merge_sort(array, left, mid);
		swap_num += merge(array, left, mid, right);
	}

	return swap_num;
}

int merge(int *array, int left, int mid, int right){
	int swap_num = 0;
	int n1 = mid - left;
	int n2 = right - mid;

	int* L = (int*)malloc((n1+1) * sizeof(int));
	int* R = (int*)malloc((n2+1) * sizeof(int));

	for(int i = 0; i < n1; ++i){
		L[i] = array[left + i];
	}
	L[n1] = INT_MAX;
	for(int i = 0; i < n2; ++i){
		R[i] = array[mid + i];
	}
	R[n2] = INT_MAX;

	int i = 0;
	int j = 0;
	for(int k = left; k < right; ++k){
		if(L[i] <= R[j]){
			array[k] = L[i];
			++i;
		}else{
			array[k] = R[j];
			++j;
		}
	}
	swap_num = right - left;
	return swap_num;
}

void print_array(int *array, int size){
	for(int i = 0; i < size; i++){
		cout <<  array[i];
		if(i != size - 1){
		cout << " " ;
		}
	}
	cout << endl;
}
