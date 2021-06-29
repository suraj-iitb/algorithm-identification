#include <iostream>
#include <string>

using namespace std;


struct {
	unsigned int num;
	char s;
}typedef card;

// Variables for mergesort
const unsigned int MAX = 100000;
card L[MAX / 2 + 2];
card R[MAX / 2 + 2];
const int SENTINEL = 2000000000;

// Merge
void Merge(card A[], int left, int mid, int right)
{
	int n1 = mid - left;
	int n2 = right - mid;
	for (int i = 0; i < n1; i++)
		L[i] = A[left + i];
	for (int i = 0; i < n2; i++)
		R[i] = A[mid + i];
	L[n1].num = SENTINEL;
	R[n2].num = SENTINEL;

	int i = 0;
	int j = 0;
	for (int k = left; k < right; k++) {
		if (L[i].num <= R[j].num) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}
	}
}

// Merge sort
void Mergesort(card A[], int left, int right)
{
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		Mergesort(A, left, mid);
		Mergesort(A, mid, right);
		Merge(A, left, mid, right);
	}

}

// Exchange
void exchange(card A[], int i, int j)
{
	card tmp = A[i];
	A[i] = A[j];
	A[j] = tmp;
}

// Partition
int partition(card A[], int l, int r)
{
	unsigned int threshold = A[r].num;
	int i = l - 1;
	for (int j = l; j < r; j++) {
		if (A[j].num <= threshold) {
			i++;
			// Exchange
			exchange(A, i, j);
		}
	}
	i++;
	// Insert threshold
	exchange(A, i, r);
	return i;
}

// Quicksort
void quicksort(card A[], int l, int r)
{
	if (l >= r)
		return;
	int p = partition(A, l, r);
	quicksort(A, l, p - 1);
	quicksort(A, p + 1, r);
}

// MAIN FUNCTION
int main(int argc, char** argv)
{
	// Input
	card A[100000];
	card B[100000];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i].s >> A[i].num;
		B[i] = A[i];
	}

	// Quicksort
	quicksort(A, 0, n - 1);

	// Mergesort
	Mergesort(B, 0, n);

	// Check if quicksort is stable
	bool stable = true;
	for (int i = 0; i < n; i++) 
		if (A[i].s != B[i].s)
			stable = false;
	
	// Print all elements
	if (stable)
		cout << "Stable" << endl;
	else
		cout << "Not stable" << endl;

	for (int i = 0; i < n; i++) {
		cout << A[i].s << " " << A[i].num << endl;
	}

	return 0;
}
