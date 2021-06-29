#include <iostream>
using namespace std;

void insertionSort(int a[], int n) 
{
	for(int i=1; i<n; i++) {
		int key = a[i];
		int j = i-1;
		while(j>=0 && a[j] > key) {
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
		for(int i=0; i<n; i++) {
			if(i>0)
				cout << " "; 
			cout << a[i];
		}
		cout << endl;
	}
}
int main(){

	int n;
	cin >> n;
	int array[1000];

	for(int i=0; i<n; i++) {
		cin >> array[i];
	}

	for(int i=0; i<n; i++) {
		if(i>0)
			cout << " ";
		cout << array[i];
	}
	cout << endl;

	insertionSort(array, n);
}

