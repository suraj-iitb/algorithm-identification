#include<iostream>
int main() {
	using namespace std;
	int len;
	cin >> len;
	int* arr = new int[len];
	for (int i = 0; i < len; i++)
		cin >> arr[i];
	int step = 0;
	for (int i = 0; i < len; i++) {
		for (int j = len - 1; j > i; j--) {
			if (arr[j] < arr[j - 1]) {
				swap(arr[j], arr[j - 1]);
				step++;
			}
		}
	}
	for (int i = 0; i < len; i++) {
		if (i)
			cout << " ";
		cout << arr[i];
	}
	cout << endl;
	cout << step<<endl;
	return 0;
}
