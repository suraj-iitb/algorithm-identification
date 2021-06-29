#include <iostream>
using namespace std;


int selectionSort(int arr[], int n){
	int min_i;
	int swapCount = 0;
	for(int i = 0; i < n; i++){
		min_i = i;
		for(int j = i; j < n; j++){
			if( arr[j] < arr[min_i] ){
				min_i = j;
			}
		}
		if(i != min_i){
			swap(arr[i], arr[min_i]);
			swapCount++;
		}
	}
	return swapCount;
}

void printArr(int arr[], int n){
	for(int i = 0; i < n; i++){
		cout << arr[i];
		if(i != n - 1){
			cout << ' ';
		}
	}
	cout << endl;
}

int main(){
	int n;
	int arr[100];
	int swapCount;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	swapCount = selectionSort(arr, n);
	printArr(arr, n);
	cout << swapCount << endl;

	return 0;
}
