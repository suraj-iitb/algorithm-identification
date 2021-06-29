#include<iostream>
using namespace std;

static const int MAX = 500000;
static const int INFTY = 2000000000;

int L[MAX / 2 + 2], R[MAX / 2 + 2];
int total;


void merge(int S[], int left, int mid, int right) {
	int n1 = mid - left;
	int n2 = right - mid;
	for (int i = 0; i < n1; i++) {
		L[i] = S[left + i];
	}
	for (int i = 0; i < n2; i++) {
		R[i] = S[mid + i];
	}
	L[n1] = INFTY;
	R[n2] = INFTY;
	int i = 0, j = 0;
	for (int k = left; k < right; k++) {
		total += 1;
		if (L[i] <= R[j]) {
			S[k] = L[i];
			i++;
		}
		else {
			S[k] = R[j];
			j++;
		}
	}
}

void mergeSort(int S[], int left, int right) {
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		mergeSort(S, left, mid);
		mergeSort(S, mid, right);
		merge(S, left, mid, right);
	}
}

int main() {
	total = 0;
	int S[MAX];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> S[i];
	}
	mergeSort(S, 0, n);
	for (int i = 0; i < n; i++) {
		if (i > 0) {
			cout << " ";
		}
		cout << S[i];
	}
	cout << endl;
	cout << total << endl;
	return 0;
}
