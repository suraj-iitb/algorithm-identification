#include <iostream>

using namespace std;

void printArr(int a[], int len) {


	for (int i = 0; i < len; i++)
	{
		if (i == 0) cout << a[0];
		else cout << " " << a[i];
	}
	cout << endl;
}

int bubbleSort(int a[], int len) {

	int count = 0;
	bool flag = false;	//是否完成
	for (int i = 0; i < len; i++) {
		flag = true;
		for (int j = len - 1; j > i; j--) {
			if (a[j] < a[j - 1]) {
				swap(a[j], a[j - 1]);
				count++;
				flag = false;
			}
		}
		if (flag) return count;
	}
	return count;
}

int main() {

	int n;
	cin >> n;
	
	int* r = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> r[i];
	}

	int count = bubbleSort(r, n);
	printArr(r, n);
	cout << count << endl;

	delete[] r;
	return 0;
}

