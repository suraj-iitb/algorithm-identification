#include<iostream>

const int K = 10000;

// Countingsort
void countingsort(int A[], int B[], int n)
{
	int C[10001];
	// Initialize
	for (int i = 0; i <= K; i++)
		C[i] = 0;
	// Count frequency
	for (int i = 0; i < n; i++)
		C[A[i]]++;
	// Calculate cumulative sum
	for (int i = 1; i <= K; i++)
		C[i] = C[i] + C[i - 1];
	for (int i = n - 1; i >= 0; i--) {
		B[C[A[i]] - 1] = A[i];
		C[A[i]]--;
	}
}

// MAIN FUNCTION
int main()
{
	// Input
	int n;
	int A[2000000];
	std::cin >> n;
	A[0] = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> A[i];
	}

	// Counting sort
	int B[2000000];
	countingsort(A, B, n);
	for (int i = 0; i < n; i++) {
		if (i)
			std::cout << " ";
		std::cout << B[i];
	}
	std::cout << std::endl;
	return 0;
}
