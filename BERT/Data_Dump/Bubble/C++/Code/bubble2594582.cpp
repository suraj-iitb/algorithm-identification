#include <iostream>
using namespace std;

int bubbleSort(int A[], int N){
	int swapNumber = 0;
	int flag = 1;
	int i, j;
	for(i = 0; flag; i++){
		flag = 0;
		for(j = N-1; j >= i+1; j--){
			if(A[j - 1] > A[j]){
				flag = 1;
				swap(A[j], A[j - 1]);
				swapNumber++;
			}
		}
	}
	return swapNumber;
}
int main(int argc, char const *argv[])
{
	int A[100];
	int N, swapNumber;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	swapNumber = bubbleSort(A, N);
	for(int i = 0; i < N; i++){
		if(i){
			cout << " ";
		}
		cout << A[i];
	}
	cout << endl;
	cout << swapNumber <<endl;
	return 0;
}
