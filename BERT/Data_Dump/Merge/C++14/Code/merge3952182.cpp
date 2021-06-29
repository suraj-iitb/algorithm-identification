#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define INFTY 1.0e9
#define N 500000
int merge_count = 0;
int array[N];

void merge(int left, int right) {
	int mid = (left+right)/2;
	int n1 = mid-left;
	int n2 = right-mid;
	int l[n1+1];
	int r[n2+1];
	for(int i = 0; i < n1; i++) {
		l[i] = array[left+i];
	}
	for(int i = 0; i < n2; i++) {
		r[i] = array[mid+i];
	}
	l[n1] = INFTY;
	r[n2] = INFTY;

	int p = 0;
	int q = 0;

	for(int i = left; i < right; i++) {
		merge_count++;
		if(l[p] <= r[q]) {
			array[i] = l[p];
			p++;
		}
		else {
			array[i] = r[q];
			q++;
		}
	}
	
}

void merge_sort(int left, int right) {
	if(left+1 < right) {
		int mid = (left+right)/2;
		merge_sort(left, mid);
		merge_sort(mid, right);
		merge(left, right);
	}
}

int main() {
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> array[i];
	}

	merge_sort(0, n);

	for(int i = 0; i < n-1; i++) {
		cout << array[i] << " ";
	}
	cout << array[n-1];
	cout << endl;

	cout << merge_count << endl;
	return 0;
}

