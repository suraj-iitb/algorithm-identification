// Aizu - ALDS 1_1_A
#include <iostream>
using namespace std;

inline void printArr(int* arr, int L, int R) {
	for(int i=L; i<=R; i++) cout << arr[i] << (i==R ? "\n" : " ");
}

void InsertionSort(int* arr, int L, int R) {
	for(int i=L+1; i<=R; i++) {
		int key = arr[i], j = i-1;
		while(j >= 1 and arr[j] > key) { arr[j+1] = arr[j]; j--; }
		arr[j+1] = key;
		printArr(arr, L, R);
	}
}

int main() {
	int N;
	cin >> N;
	int* arr = new int [N+1];
	for(int i=1; i<=N; i++) cin >> arr[i];
	
	printArr(arr, 1, N);
	InsertionSort(arr, 1, N);
}
