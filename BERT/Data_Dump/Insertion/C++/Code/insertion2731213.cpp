#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int temp;
	int i = 1;
	for (; i < n; i++) {
		for (int i=0; i < n; i++) {
			cout << arr[i];
			if (i != n - 1)
				cout << ' ';
			else
				cout << endl;
		}
		int j = i - 1;
		temp = arr[j+1];
		while (arr[j] > temp&&j>=0) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i];
		if (i != n - 1)
			cout << ' ';
		else
			cout << endl;
	}
return 0;
}
