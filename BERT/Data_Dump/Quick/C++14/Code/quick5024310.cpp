#include<iostream>
#include<stdio.h>
using namespace std;



struct Card {
	char mark;
	int number;
};

struct Card A[100000], L[50002], R[50002];

void merge(struct Card A[], int n, int left, int mid, int right) {
	int n1 = mid - left;
	int n2 = right - mid;
	for (int i = 0; i < n1; i++) {
		L[i] = A[left + i];
	}
	for (int i = 0; i < n2; i++) {
		R[i] = A[mid + i];
	}
	L[n1].number = 2000000000;
	R[n2].number = 2000000000;
	int i = 0;
	int j = 0;
	for (int k = left; k < right; k++) {
		if (L[i].number <= R[j].number) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}
	}
}


void mergeSort(struct Card A[], int n, int left, int right) {
	int mid;
	if (left + 1 < right) {
		mid = (left + right) / 2;
		mergeSort(A, n, left, mid);
		mergeSort(A, n, mid, right);
		merge(A, n, left, mid, right);
	}
}

int partition(struct Card A[], int p, int r) {
	struct Card x;
	x = A[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (A[j].number <= x.number) {
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[r]);
	return i + 1;
}

void quicksort(struct Card A[], int p, int r) {
	int q;
	if (p < r) {
		q = partition(A, p, r);
		quicksort(A, p, q - 1);
		quicksort(A, q + 1, r);
	}
}

int main() {
	int n;
	cin >> n;
	int k;
	char m;
	class Card A[1000000], B[1000000];
	int stable = 1;
	for (int i = 0; i < n; i++) {
		cin >> m >> k;
		A[i].mark = B[i].mark = m;
		A[i].number = B[i].number = k;
	}

	quicksort(A, 0, n - 1);
	mergeSort(B, n, 0, n);

	for (int i = 0; i < n; i++) {
		if (A[i].mark != B[i].mark) {
			stable = 0;
		}
	}

	if (stable == 1) {
		cout << "Stable" << endl;
	}
	else {
		cout << "Not stable" << endl;
	}

	for (int i = 0; i < n; i++) {
		cout << A[i].mark << " " << A[i].number << endl;
	}

	return 0;
}

