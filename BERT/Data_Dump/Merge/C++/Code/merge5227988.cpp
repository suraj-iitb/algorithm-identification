#include <iostream>
using namespace std;

int count = 0;

void merge (int a[], int left, int mid, int right) {
	int n1 = mid - left;
	int n2 = right - mid;

	int l[n1];
	for (int i = 0; i < n1; i++) {
		l[i] = a[left + i];
	}
	l[n1] = 1000000001;
	int r[n2];
	for (int i = 0; i < n2; i++) {
		r[i] = a[mid + i];
	}
	r[n2] = 1000000001;

	int li = 0;
	int ri = 0;
	for (int i = left; i < right; i++) {
		count++;
		if (l[li] <= r[ri]) {
			a[i] = l[li];
			li++;
		} else if (l[li] > r[ri]) {
			a[i] = r[ri];
			ri++;
		}
	}
}

void mergeSort (int a[], int left, int right) {
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		mergeSort(a, left, mid);
		mergeSort(a, mid, right);
		merge(a, left, mid, right);
	}
}

int main () {
	int n;
    cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	mergeSort(a, 0, n);

	for (int i = 0; i < n; i++) {
		if (i > 0) cout << ' ';
		cout << a[i];
	}
	cout << endl;

	cout << count << endl;

	return 0;
}

