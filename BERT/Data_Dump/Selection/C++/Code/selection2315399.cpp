#include <iostream>

#define SIZE 100

using namespace std;

void selectionSort(int, int[]);

int main(void) {
	int n, list[SIZE];
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> list[i];
	}

	selectionSort(n, list);

	return 0;
}

void selectionSort(int n, int list[]) {
	int count = 0;
	int min, tmp;
	for (int i = 0; i < n; i++) {
		min = i;
		for (int j = i; j < n; j++) {
			if (list[j] < list[min]) {
				min = j;
			}
		}
		tmp = list[i];
		list[i] = list[min];
		list[min] = tmp;
		if (i != min) {
			count++;
		}
	}
	for (int i = 0; i < n; i++) {
		if (i > 0) {
			cout << " ";
		}
		cout << list[i];
	}
	cout << "\n" << count << "\n";
}
