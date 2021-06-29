#include<iostream>
int main() {
	using std::cin;
	using std::cout;
	int len;
	cin >> len;
	int* arr = new int[len];
	for (int i = 0; i < len; i++)
		cin >> arr[i];

	for (int j = 0; j < len; j++) {
		if (j)
			cout << " ";
		cout << arr[j];
	}
	cout << "\n";
	for (int i = 1; i < len; i++) {
		int j = i - 1;
		int temp = arr[i];
		while(j >= 0 && temp<arr[j]) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
		for (int j = 0; j < len; j++) {
			if (j)
				cout << " ";
			cout << arr[j];
		}
		cout << "\n";
	}
	return 0;
}

