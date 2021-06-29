#include <bits/stdc++.h>

using namespace std;

int partition(vector<pair<int,string>> &a, int p, int r) {

	int x = a[r].first;
	int i = p-1;
	for (int j = p; j < r; j++) {
		if (a[j].first <= x) {
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i+1], a[r]);
	return i+1;

}

int quicksort(vector<pair<int,string>>&a, int p, int r) {
	if (p < r) {
		int q = partition(a, p, r);
		quicksort(a, p, q - 1);
		quicksort(a, q + 1, r);
	}
	return 0;
}


int merge(vector<pair<int,string>> &a, int left, int mid, int right, int &counter) {
	int n1 = mid - left;
	int n2 = right - mid;
	vector<pair<int,string>> l(n1 + 1, pair<int,string>());
	vector<pair<int,string>> r(n2 + 1, pair<int,string>());

	for (int i = 0; i < n1; i++) {
		l[i] = a[left + i];
	}
	for (int i = 0; i < n2; i++) {
		r[i] = a[mid + i];
	}
	l[n1].first = INT_MAX;
	r[n2].first = INT_MAX;

	int i = 0;
	int j = 0;

	for (int k = left; k < right; k++) {
		counter++;
		if (l[i].first <= r[j].first) {
			a[k] = l[i];
			i++;
		}
		else {
			a[k] = r[j];
			j++;
		}
	}
	return 0;
}

int mergeSort(vector<pair<int,string>> &a, int left, int right, int &counter) {
	if (left + 1 >= right) {
		return 0;
	}

	int mid = (left + right) / 2;

	mergeSort(a, left, mid, counter);
	mergeSort(a, mid, right, counter);
	merge(a, left, mid, right, counter);
	return 0;
}


int main() {

	int n;
	cin >> n;

	vector<pair<int,string>> a(n, pair<int,string> ());

	for (int i = 0; i < n; i++) {
		cin >> a[i].second >> a[i].first;
	}
	vector<pair<int, string>> b(n, pair<int, string>());
	b = a;

	int p = 0;
	int r = n - 1;
	quicksort(a, p, r);

		int left = 0, right = n;
	int counter = 0;

	mergeSort(b, left, right, counter);

	for (int i = 0; i < n; i++) {

		if (a[i].second != b[i].second) {
			cout << "Not stable" << endl;
			break;
		}
		if (i == n - 1) {
			cout << "Stable" << endl;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << a[i].second << " " << a[i].first << endl;
	}
}
