#include <iostream>
using namespace std;

int bubbleSort(int a[], int n) {
	int flag = 1;
	int counter = 0;
	while(flag) {
		flag = 0;
		for(int j=n-1; j>=1;j--) {
			if(a[j] < a[j-1]) {
				swap(a[j], a[j-1]);
				counter++;
			    flag = 1;
			}
		}
	}
	return counter;
}
int main() {
	int array[100];
	int n;
	int changeCounter;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> array[i];
	}

	changeCounter = bubbleSort(array,n);

	for(int i=0; i<n; i++) {
		if(i>0)
			cout << " ";
		cout << array[i];
	}
	cout << endl;

	cout << changeCounter << endl;

}
