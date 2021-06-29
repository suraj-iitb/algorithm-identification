#include <iostream>
using namespace std;

int selectionSort(int a[], int n) {
	int counter=0;
	for(int i=0; i<n; i++) {
		int minj = i;
		for(int j=i; j<n; j++) {
			if(a[j] < a[minj])
				minj = j;
		}
		if(i!=minj) {
		swap(a[i],a[minj]);
		counter++;
		}
	}
	return counter;
}

int main() {
	int array[100];
	int n;
	int counter;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> array[i];
	}

	counter = selectionSort(array, n);

	for(int i=0; i<n; i++) {
		if(i>0)
			cout << " ";
		cout << array[i];
	}
	cout << endl;

	cout << counter << endl;

}


