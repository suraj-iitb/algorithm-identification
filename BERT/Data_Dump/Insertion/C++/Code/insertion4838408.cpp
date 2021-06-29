#include<iostream>
using namespace std;

void Cout(int a[], int n) {
	int j;
	for (j = 0; j < n; j++) {
	    if(j<n-1){
	        cout << a[j] << " ";
	    }
	    else{
	        cout << a[j] << endl;
	    }
	}
}

void insertionSort(int a[], int n) {
	int i, j, t;

	for (i = 1; i < n; i++) {

		t = a[i];
		for (j = i - 1; (j >= 0 && a[j] > t); j--) {
			a[j + 1] = a[j];
		}
		a[j + 1] = t;

		Cout(a, n);
	}
}

int main() {
	int n, a[100], i;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}

	Cout(a, n);
	insertionSort(a, n);

	return 0;
}
