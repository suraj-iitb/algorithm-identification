#include <iostream>
#include <climits>

void swap(int& x, int& y)
{
	int tmp = x;
	x = y;
	y = tmp;
}

void swap(char& x, char& y)
{
	char tmp = x;
	x = y;
	y = tmp;
}

void stable_merge(char* S, int *A, int left, int mid, int right)
{
	int n1 = mid - left;
	int n2 = right - mid;
	int* L = new int[n1+1];
	int* R = new int[n2+1];
	char* LS = new char[n1+1];
	char* RS = new char[n2+1];
	for (int i=left; i<mid; i++) {
		L[i-left] = A[i];
		LS[i-left] = S[i];
	}
	for (int i=mid; i<right; i++) {
		R[i-mid] = A[i];
		RS[i-mid] = S[i];
	}
	L[n1] = R[n2] = INT_MAX;
	LS[n1] = RS[n2] = CHAR_MAX;
	int l = 0, r = 0;
	for (int k=left; k<right; k++) {
		if (L[l] > R[r]) {
			A[k] = R[r]; S[k] = RS[r]; r++;
		} else {
			A[k] = L[l]; S[k] = LS[l]; l++;
		}
	}
	delete[] L;
	delete[] R;
	delete[] LS;
	delete[] RS;
}

void stable_mergeSort(char* S, int *A, int left, int right)
{
	if (left+1 < right) {
		int mid = (left + right) / 2;
		stable_mergeSort(S, A, left, mid);
		stable_mergeSort(S, A, mid, right);
		stable_merge(S, A, left, mid, right);
	}
}

int partition(char* S, int* A, int p, int r)
{
	int key = A[r];
	int i = p - 1;
	for (int j=p; j<r; j++) {
		if (A[j] <= key) {
			i++;
			swap(A[i], A[j]);
			swap(S[i], S[j]);
		}
	}
	swap(A[i+1], A[r]);
	swap(S[i+1], S[r]);
	return i+1;
}

void quickSort(char* S, int* A, int p, int r)
{
	if (p<r) {
		int q = partition(S, A, p, r);
		quickSort(S, A, p, q-1);
		quickSort(S, A, q+1, r);
	}
}

int main()
{
	int n;
	std::cin >> n;
	
	char* suits = new char[n];
	int *nums = new int[n];
	
	for (int i=0; i<n; i++) std::cin >> suits[i] >> nums[i];
	
	char* suits_cpy = new char[n];
	int *nums_cpy = new int[n];
	
	for (int i=0; i<n; i++) {
		suits_cpy[i] = suits[i];
		nums_cpy[i] = nums[i];
	}
	
	quickSort(suits, nums, 0, n-1);
	stable_mergeSort(suits_cpy, nums_cpy, 0, n);
	
	bool isStable = true;
	for (int i=0; i<n; i++) {
		if (suits[i] != suits_cpy[i]) {
			isStable = false; break;
		}
	}
	
	if (isStable) std::cout << "Stable" << std::endl;
	else std::cout << "Not stable" << std::endl;
	for (int i=0; i<n; i++) {
		std::cout << suits[i] << " " << nums[i] << std::endl;
	}
	
	delete[] suits;
	delete[] nums;
	delete[] suits_cpy;
	delete[] nums_cpy;
	
	return 0;
}


