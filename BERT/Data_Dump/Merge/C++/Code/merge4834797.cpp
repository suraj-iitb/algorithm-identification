#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<list>
#include<numeric>
#include<queue>
#include<stack>
#include<stdio.h>
#include<string>
#include<vector>

using namespace std;

const int SENTINEL = 2000000000;
const double PI = acos(-1);

void print_array(int n, int array[]) {
	for (int i = 0; i < n; i++) {
		if (i > 0) cout << " ";
		cout << array[i];
	}
	cout << endl;
}

void print_list(list<int> lst) {
	list<int>::iterator itr;
	for (itr = lst.begin(); itr != lst.end(); itr++) {
		if (itr != lst.begin()) cout << " ";
		cout << *itr;
	}
	cout << endl;
}

const int MAX = 500000;
int L[MAX / 2 + 2], R[MAX / 2 + 2];
int a[MAX];
int cnt = 0;

void merge(int a[], int left, int mid, int right) {
	int n1 = mid - left;
	int n2 = right - mid;
	for (int i = 0; i < n1; i++) L[i] = a[left + i];
	for (int i = 0; i < n2; i++) R[i] = a[mid + i];
	L[n1] = R[n2] = SENTINEL;
	int i = 0, j = 0;
	for (int k = left; k < right; k++) {
		cnt++;
		if (L[i] <= R[j]) {
			a[k] = L[i++];
		} else {
			a[k] = R[j++];
		}
	}
}

void mergeSort(int a[], int left, int right) {
	if (left + 1 >= right) return;
	int mid = (left + right) / 2;
	mergeSort(a, left, mid);
	mergeSort(a, mid, right);
	merge(a, left, mid, right);
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	mergeSort(a, 0, n);
	print_array(n, a);
	cout << cnt << endl;
	return 0;
}

