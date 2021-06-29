#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <string>
#include <queue>
#include <vector>
using namespace std;

struct Card {
	string suit;
	int number;
};
Card A[100000];
Card B[100000];

int partition(Card A[], int p, int r) {
	int x = A[r].number;
	int i = p - 1;

	for (int j = p; j < r; j++) {
		if (A[j].number <= x) {
			i++;
			swap(A[i], A[j]);
		}
	}

	swap(A[i + 1], A[r]);
	return i + 1;
}

void quickSort(Card A[], int p, int r) {
	if (p < r) {
		int q = partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}

Card L[500001];
Card R[500001];

void merge(Card B[], int left, int mid, int right) {
	int n1 = mid - left;
	int n2 = right - mid;
	for (int i = 0; i < n1; i++) L[i] = B[left + i];
	for (int i = 0; i < n2; i++) R[i] = B[mid + i];
	L[n1].number = 1000000001;
	R[n2].number = 1000000001;

	int i = 0, j = 0;
	for (int k = left; k < right; k++) {
		if (L[i].number <= R[j].number) {
			B[k] = L[i];
			i++;
		}
		else {
			B[k] = R[j];
			j++;
		}
	}
}

void mergeSort(Card B[], int left, int right) {
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		mergeSort(B, left, mid);
		mergeSort(B, mid, right);
		merge(B, left, mid, right);
	}
}


int main()
{
	Card c;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c.suit >> c.number;
		A[i] = c;
		B[i] = c;
	};

	mergeSort(B, 0, n);
	quickSort(A, 0, n - 1);

	bool s = true;
	for (int i = 0; i < n; i++) {
		if (A[i].suit != B[i].suit || A[i].number != B[i].number) {
			s = false;
			break;
		}
	}

	if (s) cout << "Stable" << endl;
	else cout << "Not stable" << endl;

	for (int i = 0; i < n; i++) {
		cout << A[i].suit << " " << A[i].number << endl;
	}
}

