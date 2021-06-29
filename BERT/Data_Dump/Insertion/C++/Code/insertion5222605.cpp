#include <iostream>
#include <algorithm>
#include <string>
#include <cmath> 
#include <vector>
#include <iomanip>
#include <locale>

const double PI = 3.141592653589;

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> array(n);

	for (int i = 0; i < n; i++) cin >> array[i];

	for (int i = 0; i < n; i++) {
		int tmp = array[i];
		int j = i - 1;
		while (j >= 0 && array[j] > tmp) {
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = tmp;

		for (int k = 0; k < n-1; k++) {
			cout << array[k] << " ";
		}
		cout << array[n-1] <<endl;
	}


	return 0;
}
