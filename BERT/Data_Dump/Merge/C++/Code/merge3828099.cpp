#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
vector<int> arr, tmp;
int cnt;

void print(vector<int>& arr) {
	int n = arr.size();
	for (int i = 0; i < n; ++i) {
		cout << arr[i];
		if (i != n - 1) cout << " ";
	}
	cout << endl;
}

void insert_sort(vector<int>& arr) {
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

void select_sort(vector<int>& arr) {
	int n = arr.size();
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		int mi_idx = i;
		for (int j = i; j < n; ++j) {
			if (arr[j] < arr[mi_idx])
				mi_idx = j;
		}
		cnt += (i != mi_idx);
		swap(arr[i], arr[mi_idx]);
	}
	print(arr);
	cout << cnt << endl;
}

void merge(vector<int> &arr, int a, int b, int c) {
	for (int i = a; i <= c; ++i)
		tmp[i] = arr[i];

	int i = a;
	int j = b + 1;
	while (i <= b && j <= c) {
		cnt++;
		if (tmp[i] <= tmp[j]) arr[a++] = tmp[i++];
		else arr[a++] = tmp[j++];
	}
	while (i <= b) { arr[a++] = tmp[i++]; cnt++; };
	while (j <= c) { arr[a++] = tmp[j++]; cnt++; }
}

void merge_sort(vector<int>& arr, int l, int r) {
	if (l < r) {
		int mid = l + (r - l) / 2;
		merge_sort(arr, l, mid);
		merge_sort(arr, mid+1, r);
		merge(arr, l, mid, r);
	}
}

int main() {
	int n; cin >> n;

	arr.assign(n, 0);
	tmp.assign(n, 0);
	cnt = 0;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	merge_sort(arr, 0, n - 1);
	print(arr);
	cout << cnt << endl;

	return 0;
}

