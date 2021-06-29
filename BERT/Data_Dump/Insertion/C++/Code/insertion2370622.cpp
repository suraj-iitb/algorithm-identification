#include<iostream>
#include<fstream>
using namespace std;


// do insertion sort for console input data
int main() {
	int size;
	cin >> size;

	int* nums = new int[size];
	int num;

	for (int i = 0; i < size; i++) {
		cin >> nums[i];
	}

	// first row output
	for (int i = 0; i < size - 1; i++) {
		cout << nums[i] << ' ';
	}
	cout << nums[size - 1] << endl;

	// do insertion sort
	for (int i = 1; i < size; i++) {
		int j = i - 1;
		num = nums[i];
		while (j >= 0 && num < nums[j]) {
			nums[j + 1] = nums[j];
			j--;
		}
		nums[j + 1] = num;

		// output of every steps
		for (int k = 0; k < size-1; k++) {
			cin >> nums[k];
			cout << nums[k] << ' ';
		}
		cout << nums[size-1];

		if (i != size) cout << endl;
	}
}
