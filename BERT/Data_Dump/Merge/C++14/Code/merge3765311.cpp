#include <bits/stdc++.h>

using namespace std;

int merge(vector<int> &a, int left, int mid, int right,  int &counter) {
	int n1 = mid - left;
	int n2 = right - mid;
	vector<int> l(n1 + 1, 0);
	vector<int> r(n2 + 1, 0);

	for (int i = 0; i < n1 ; i++) {
		l[i] = a[left + i];
	}
	for (int i = 0; i < n2 ; i++) {
		r[i] = a[mid + i];
	}
	l[n1] = INT_MAX;
	r[n2] = INT_MAX;

	int i = 0;
	int j = 0;

	for (int k = left; k < right;k++) {
		counter++;
		if (l[i] <= r[j]) {
			a[k]=l[i];
				i++;
		}
		else {
			a[k]=r[j];
			j++;
		}
	}
	return 0;
}

int mergeSort(vector<int> &a, int left, int right,int &counter) {
	if (left + 1 >= right) {
		return 0;
	}
	
	int mid = (left + right) / 2;

	mergeSort(a, left, mid,  counter);
	mergeSort(a, mid, right,  counter);
	merge(a, left, mid, right, counter);
	return 0;
}


int main() {

	int n;
	cin >> n;
	vector<int> a(n,0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int left=0, right=n;
	int counter = 0;
	mergeSort(a, left, right,counter);
	
	for (int i = 0; i < n; i++) {
		cout << a[i] << (i != n - 1 ? " " : "\n");
	}
	cout << counter << endl;


}
