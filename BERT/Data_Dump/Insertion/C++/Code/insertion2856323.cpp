#include <iostream>

int main() {

	int n = 0, i = 0, j = 0, v = 0, count = 0;
	std::cin >> n;

	int a[100];

	for (i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	for (count = 0; count < n-1; count++) {
		std::cout << a[count] << " ";
			}
	std::cout << a[n-1]<<std::endl;

	for (i = 1; i < n; i++) {
		v = a[i];
		j = i - 1;

		while ((j >= 0) && (a[j] > v)) {
			a[j + 1] = a[j];
			j--;
		}

		a[j + 1] = v;

		for (count = 0; count < n-1; count++) {
			std::cout << a[count] << " ";

		}
		std::cout <<a[n-1]<< "\n";

	}


	return 0;


}
