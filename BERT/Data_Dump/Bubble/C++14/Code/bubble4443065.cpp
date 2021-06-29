#include <iostream>

#define N_MAX 100

using namespace std;

int bubbleSort(int* A, const int N);

int main() {
	ios::sync_with_stdio(false);

	int N, A[N_MAX], swapCount;
	swapCount = 0;
	
	cin >> N;
	for(int i = 0; i < N; ++i) {
		cin >> A[i];
	}

	swapCount = bubbleSort(A, N);

	for(int i = 0; i < N; ++i){
		cout << A[i] << (N - 1 == i ? "\n" : " ");
	}
	cout << swapCount << endl;
	return 0;
}

int bubbleSort(int* A, const int N){
	int swapCount = 0;
	bool flag = true;
	while(flag){
		flag = false;
		for(int i = N - 1; i > 0; --i){
			if(A[i] < A[i-1]){
				swap(A[i], A[i - 1]);
				swapCount++;
				flag = true;
			}
		}
	}
	return swapCount;
}
