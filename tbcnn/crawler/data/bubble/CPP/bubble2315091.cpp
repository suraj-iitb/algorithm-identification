#include <iostream>

#define SIZE 100

using namespace std;

void bubbleSort(int, int[]);

int main(void) {
	int n, list[SIZE];
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> list[i];
	}

	bubbleSort(n, list);

	return 0;
}

void bubbleSort(int n, int list[]) {
	int count = 0;
	int tmp;
	bool flag = true;
	for (int i = 0; i < n; i++) {
		while (flag) {
			flag = false;
			for (int j = n - 1; j >= i + 1; j--) {
				if (list[j] < list[j - 1]) {
					tmp = list[j];
					list[j] = list[j - 1];
					list[j - 1] = tmp;
					count++;
					flag = true;
				}
			}
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
