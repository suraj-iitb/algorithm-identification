#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void print(vector<int>& arr) {
	int n = arr.size();
	for (int i = 0; i < n; ++i) {
		cout << arr[i];
		if (i != n - 1) cout << " ";
	}
	cout << endl;
}

void insert_sort(vector<int> &arr) {
	int n = arr.size();
	for (int i = 0; i < n; ++i) {
		for (int j = i; j > 0; --j) {
			if (arr[j - 1] > arr[j])
				swap(arr[j - 1], arr[j]);
		}
		print(arr);
	}
}

void bubble_sort(vector<int>& arr) {
	int n = arr.size();
	int cnt = 0;
	for (int i = 0; i < arr.size(); ++i) {
		for (int j = n - 1; j > i; --j) {
			if (arr[j] < arr[j - 1]) {
				swap(arr[j - 1], arr[j]);
				cnt++;
			}
		}
	}
	print(arr);
	cout << cnt << endl;
}


int main() {
	int n; cin >> n;

	vector<int> arr(n, 0);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	bubble_sort(arr);

	return 0;
}

