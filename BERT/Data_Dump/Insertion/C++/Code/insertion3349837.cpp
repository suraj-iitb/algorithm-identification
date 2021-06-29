
#include <iostream>
#include <iomanip>

void Output(int arr[], int n) {
	for (int i = 0; i < n - 1; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << arr[n - 1] << std::endl;
}

void Insection(int arr[], int n) {
	for (int i = 1; i < n; ++i) {
		int v = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > v) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = v;
		Output(arr, n);
	}

}

int main()
{
	int arr[100];
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> arr[i];
	}
	Output(arr, n);
	Insection(arr, n);
}

