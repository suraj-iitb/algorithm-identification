#include<iostream>
using namespace std;

int swapCount = 0;
void bubbleSort(int* A, int n){
	bool flag = true;
	while(flag){
	flag = false;
		for(int j = n - 1; j >= 1; j--){
			if(A[j] < A[j - 1]){
				int temp = A[j - 1];
				A[j-1] = A[j];
				A[j] = temp;
				swapCount++;
				flag = true;
			}
		}
	}
}

int main(){
	int n = 0; 
	cin >> n;
	int A[n];
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	bubbleSort(A, n);
	cout << A[0];
	for(int i = 1; i < n; i++){
		cout << ' ' << A[i];
	}
	cout << '\n' << swapCount << '\n';
	return 0;
}
