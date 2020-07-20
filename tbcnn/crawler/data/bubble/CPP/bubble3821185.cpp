#include <iostream>
using namespace std;

//bubble sort with using flag
int bubbleSort(int A[], int n){
	int count = 0;
	bool flag = 1;
	for (int i = 0; flag; i++) {
		flag = 0;
		for (int j = n -1; j >= i + 1; j--) {
			if (A[j] < A[j-1]) {
				swap(A[j], A[j-1]);
				flag = 1;
				count++;
			}
		}
	}
	return count;
}

int main() {
	int n, A[100];
	cin >> n;

	for (int i = 0; i < n; i++) cin >> A[i];

	int c = bubbleSort(A, n);
	for (int i = 0; i < n; i++) {
		if(i) cout << " ";
		cout << A[i];
	}
	cout << endl;
	cout << c << endl;
	return 0;
	}
 
 
