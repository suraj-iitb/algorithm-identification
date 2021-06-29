#include <iostream>
using namespace std;

int bubbleSort(int arr[], int n){
	int count = 0;
	for(int i = 0; i < n; i++){
		for(int j = n - 1; j > i; j--){
			if(arr[j] < arr[j - 1]){
				swap(arr[j], arr[j - 1]);
				count++;
			}
		}
	}
	return count;
}

void printArr(int arr[], int n){
	for(int i = 0; i < n; i++){
		cout << arr[i];
		if( i != n - 1){
			cout << ' ';
		}
	}
	cout << endl;
}

int main(){
	int n;
	int arr[100];

	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	int numOfSwaps = bubbleSort(arr, n);
	printArr(arr, n);
	cout << numOfSwaps << endl;

	return 0;
}
