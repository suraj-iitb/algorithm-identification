#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;

uint32_t merge(uint32_t* A, const uint32_t left, const uint32_t mid, const uint32_t right);
uint32_t mergeSort(uint32_t* A, const uint32_t left, const uint32_t right);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	uint32_t n;
	vector<uint32_t> A;
	cin >> n;
	A.reserve(n);
	uint32_t input;
	for(uint32_t i = 0; i < n; i++) {
		cin >> input;
		A.push_back(input);
	}
	uint32_t compareCount = mergeSort(A.data(), 0, A.size());
	for(uint32_t i = 0; i < n; i++) {
		cout << A[i] << ((i == n - 1) ? "\n" : " ");
	}
	cout << compareCount << endl;

	return 0;
}

uint32_t merge(uint32_t* A, const uint32_t left, const uint32_t mid, const uint32_t right) {
	const uint32_t n1 = mid - left;
	const uint32_t n2 = right - mid;
	uint32_t L[n1 + 1], R[n2 + 1];
	uint32_t count = 0;

	for(uint32_t i = 0; i < n1; i++) {
		L[i] = A[left + i];
	}
	for(uint32_t i = 0; i < n2; i++) {
		R[i] = A[mid + i];
	}
	L[n1] = (uint32_t)-1;
	R[n2] = (uint32_t)-1;

	uint32_t i = 0;
	uint32_t j = 0;
	for(uint32_t k = left; k < right; k++) {
		if(L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		} else {
			A[k] = R[j];
			j++;
		}
		count++;
	}
	return count;
}

uint32_t mergeSort(uint32_t* A, const uint32_t left, const uint32_t right) {
	uint32_t count = 0;
	if(left + 1 < right) {
		uint32_t mid = (left + right) / 2;
		count += mergeSort(A, left, mid);
		count += mergeSort(A, mid, right);
		count += merge(A, left, mid, right);
	}
	return count;
}

