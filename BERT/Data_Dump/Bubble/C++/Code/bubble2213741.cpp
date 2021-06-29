#include<iostream>

int swap = 0;

// Bubblesort
void bubblesort(int A[], int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > 0; j--) {
			if (A[j] < A[j - 1]) {
				swap++;
				int tmp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = tmp;
			}
		}
	}
}

// MAIN FUNCTION
int main()
{
	// Input
	int n;
	int A[100];
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> A[i];
	}
	
	// Bubble sort
	bubblesort(A, n);

	for (int i = 0; i < n; i++) {
		if (i)
			std::cout << " ";
		std::cout << A[i];
	}
	std::cout << std::endl;
	std::cout << swap << std::endl;

	return 0;
}
