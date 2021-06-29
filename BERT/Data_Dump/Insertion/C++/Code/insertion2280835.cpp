#include <iostream>
#include <vector>


void trace(int a[], int n) {
	for (int i = 0; i < n-1; i++)
		std::cout << a[i] << " ";
	std::cout << a[n-1] << std::endl;
}

int main() {

	int n;
	std::cin >> n;

	int a[100]; // n is larger than 0 and smaller than 101

	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	// small <- sorted items... -> large :a[i]
	//                     a[j]( j:i-1 -> 0 ) and shifting...
	//            | a[i] < a[j] found!
	//            
	trace(a, n);
	for (int i = 1; i < n; i ++) {
		int key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j]; //shifting...
			j--;
		}
		a[j + 1] = key; // insert!
		trace(a, n);
	}


	//
	// TODO
	//
	// insertion sort is slow when shifting too large array 
	// * pointer improves it?
	// * size should be limited
	// a[] is awful
	// * can implement with std::vector<int> nicely?
	// *

	return 0;
}
