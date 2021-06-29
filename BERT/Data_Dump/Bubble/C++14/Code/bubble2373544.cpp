#include<iostream>
using namespace std;

int bubbleSort(int* vec, int size) {
	int flag = 1;
	int tmp;
	int count = 0;
	while (flag){
		int i = 0;
		flag = 0;
		for (int j = size - 1; j > i; j--) {
			if (vec[j] < vec[j - 1]) {
				tmp = vec[j];
				vec[j] = vec[j - 1];
				vec[j - 1] = tmp;
				flag = 1;
				count++;
			}
		}
		i++;
	}
	return count;
}

int main() {
	int size;
	cin >> size;
	int* arr = new int[size];

	for (int i = 0; i < size; i++) cin >> arr[i];

	int count = bubbleSort(arr, size);

	cout << arr[0];
	for (int i = 1; i < size; i++) {
		cout << ' ' << arr[i];
	}
	cout << endl << count << endl;
}
