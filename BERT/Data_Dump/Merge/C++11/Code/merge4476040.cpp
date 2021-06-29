#include <iostream>
#include <climits>

int merge(int* A, int left, int mid, int right)
{
	int n1 = mid - left;
	int n2 = right - mid;
	int *L = new int[n1+1];
	for (int i=0; i<n1; i++) L[i] = A[left + i];
	L[n1] = INT_MAX;
	int *R = new int[n2+1];
	for (int i=0; i<n2; i++) R[i] = A[mid + i];
	R[n2] = INT_MAX;
	
	int i = 0, j = 0;
	for (int k=left; k<right; k++) {
		if (L[i] <= R[j]) {
			A[k] = L[i]; i++;
		} else {
			A[k] = R[j]; j++;
		}
	}
	
	delete[] L;
	delete[] R;
	
	return right - left;
}

int mergeSort(int* A, int left, int right)
{
	int comparisons = 0;
	if (left+1 < right) {
		int mid = (left + right) / 2;
		comparisons += mergeSort(A, left, mid);
		comparisons += mergeSort(A, mid, right);
		comparisons += merge(A, left, mid, right);
	}
	return comparisons;
}

int main()
{
	int n;
	std::cin >> n;
	
	int *S = new int[n];
	for (int i=0; i<n; i++) std::cin >> S[i];
	
	int comparisons = mergeSort(S, 0, n);
	
	std::cout << S[0];
	for (int i=1; i<n; i++) std::cout << " " << S[i];
	std::cout << std::endl;
	std::cout << comparisons << std::endl;
	
	return 0;
}


