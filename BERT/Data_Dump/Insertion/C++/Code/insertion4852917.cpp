//AIZU_ALDS11A.cpp

#define AIZU_ALDS11A
#ifdef AIZU_ALDS11A

#define DEBUG
#include <iostream>
#define RANGE 100000
using namespace std;

int num;
int arr[RANGE];

void output() {
	for (int i = 0; i < num; i++) {
		if (i != 0)	cout << " ";
		cout << arr[i];
	}
	cout << endl;
}

void swap(int i, int j) {
	int t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
}

void insertionsort(int sorted) {
	if (sorted >= num - 1)	return;
#ifdef DEBUG
	output();
#endif // DEBUG
	for (int i = sorted + 1; i > 0; i--) if (arr[i] < arr[i - 1])	swap(i, i - 1);

	insertionsort(sorted + 1);
}

int main() {
	int t;

	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> t;
		arr[i] = t;
	}

	insertionsort(0);
	
	output();

	return 0;
}

#endif	//AIZU_ALDS11A
