#include <iostream>
using namespace std;

int num_swap = 0;

// Selection sort
void selection_sort(int A[], int n)
{
	for (int i = 0; i < n; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (A[j] < A[min])
				min = j;
		}
		// Swap
		if (min != i) {
			num_swap++;
			int tmp;
			tmp = A[min];
			A[min] = A[i];
			A[i] = tmp;
		}
	}
}

int main(int argc, char** argv)
{
	// Input
	int n;
	cin >> n;
	int A[100];
	for (int i = 0; i < n; i++)
		cin >> A[i];
	// Selection sort
	selection_sort(A, n);
	// Output
	for (int i = 0; i < n; i++) {
		if (i)
			cout << " ";
		cout << A[i];
	}
	cout << endl << num_swap << endl;
	return 0;
}
