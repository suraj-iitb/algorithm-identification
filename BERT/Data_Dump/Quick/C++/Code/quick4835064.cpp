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

void print_array(int n, int a[]) {
	for (int i = 0; i < n; i++) {
		if (i > 0) cout << " ";
		cout << a[i];
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

struct Card {
	char suit;
	int value;
};

const int MAX = 100000;
Card A[MAX];
Card B[MAX];
Card L[MAX / 2 + 2], R[MAX / 2 + 2];

void merge(Card a[], int left, int mid, int right) {
	int n1 = mid - left;
	int n2 = right - mid;
	for (int i = 0; i < n1; i++) L[i] = a[left + i];
	for (int i = 0; i < n2; i++) R[i] = a[mid + i];
	L[n1].value = R[n2].value = SENTINEL;
	int i = 0, j = 0;
	for (int k = left; k < right; k++) {
		if (L[i].value <= R[j].value) {
			a[k] = L[i++];
		} else {
			a[k] = R[j++];
		}
	}
}

void mergeSort(Card a[], int left, int right) {
	if (left + 1 >= right) return;
	int mid = (left + right) / 2;
	mergeSort(a, left, mid);
	mergeSort(a, mid, right);
	merge(a, left, mid, right);
}

int partition(Card a[], int p, int r) {
	int x = a[r].value;
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (a[j].value <= x) {
			i++;
			Card tmp = a[j]; a[j] = a[i]; a[i] = tmp;
		}
	}
	Card tmp = a[i + 1]; a[i + 1] = a[r]; a[r] = tmp;
	return i + 1;
}

void quicksort(Card a[], int p, int r) {
	if (p < r) {
		int q = partition(a, p, r);
		quicksort(a, p, q - 1);
		quicksort(a, q, r);
	}
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		Card card;
		cin >> card.suit >> card.value;
		A[i] = B[i] = card;
	}
	mergeSort(A, 0, n);
	quicksort(B, 0, n - 1);

	bool stable = true;
	for (int i = 0; i < n; i++) {
		if (A[i].suit != B[i].suit) {
			stable = false;
			break;
		}
	}

	cout << (stable ? "Stable" : "Not stable") << endl;
	for (int i = 0; i < n; i++) {
		cout << B[i].suit << " " << B[i].value << endl;
	}

	return 0;
}

