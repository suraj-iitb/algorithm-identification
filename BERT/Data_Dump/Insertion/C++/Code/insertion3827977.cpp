#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void insert_sort(vector<int> arr) {
	int n = arr.size();
	for (int i = 0; i < n; ++i) {
		for (int j = i; j > 0; --j) {
			if (arr[j - 1] > arr[j])
				swap(arr[j - 1], arr[j]);
		}
		for (int i = 0; i < n; ++i) {
			cout << arr[i];
			if (i != n - 1) cout << " ";
		}
		cout << endl;
	}
}


int main() {
	int n; cin >> n;

	vector<int> arr(n, 0);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	insert_sort(arr);

	return 0;
}

