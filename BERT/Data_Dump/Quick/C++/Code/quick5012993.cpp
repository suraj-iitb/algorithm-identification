
#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000001

struct Card {
	char Suit;
	int Value;
};

void merge(struct Card A[], int left, int mid, int right) {
	int n1 = mid - left;
	int n2 = right - mid;
	struct Card L[n1 + 1], R[n2 + 1];

	for (int i = 0; i < n1; i++) L[i] = A[left + i];
	for (int i = 0; i < n2; i++) R[i] = A[mid + i];

	L[n1].Value = MAX;
	R[n2].Value = MAX;
	int i = 0;
	int j = 0;

	for (int k = left; k < right; k++) {
		if (L[i].Value <= R[j].Value) {
			A[k] = L[i++];
		} else {
			A[k] = R[j++];
		}
	}

}

void mergeSort(struct Card A[], int left, int right) {
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
}

int partition(struct Card A[], int p, int r) {
	int x = A[r].Value;
	int i = p - 1;
	struct Card tmp;

	for (int j = p; j < r; j++) {
		if (A[j].Value <= x) {
			i++;
			tmp = A[j];
			A[j] = A[i];
			A[i] = tmp;
		}
	}
	tmp = A[r];
	A[r] = A[i+1];
	A[i+1] = tmp;

	return i + 1;
}

void quickSort(struct Card A[], int p, int r ) {
	if (p < r) {
		int q = partition(A, p, r);
		quickSort(A, p, q-1);
		quickSort(A, q+1, r);
	}
}

int main() {
	int n;
	cin >> n;

	struct Card A[n];
	for (int i = 0; i < n; i++) cin >> A[i].Suit >> A[i].Value;

	struct Card B[n];
	for ( int i = 0; i < n; i++) {
		B[i].Suit = A[i].Suit;
		B[i].Value = A[i].Value;
	}

	mergeSort(A, 0, n);
	quickSort(B, 0, n-1);

	for (int i = 0; i < n; i++) {
		if (A[i].Suit != B[i].Suit) {
			cout << "Not stable" << endl;
			break;
		} else if (i == n - 1) {
			cout << "Stable" << endl;
		}
	}

	for (int i = 0; i < n; i++) cout << B[i].Suit << " " << B[i].Value << endl;

	return 0;
}
