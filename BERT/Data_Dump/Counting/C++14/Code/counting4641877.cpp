#include <iostream>
#include <cstdint>
#include <cstring>
#include <vector>

using namespace std;

typedef vector<uint32_t> vec;
// using vec = vector<uint32_t>;

void CountingSort(const vec& A, vec& B, const uint32_t k);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	uint32_t n;
	cin >> n;

	vec A(n), B(n, 0);
	uint32_t max = 0;
	for(auto&& e : A) {
		cin >> e;
		if(max < e) { max = e; }
	}

	CountingSort(A, B, max);

	for(uint32_t i = 0; i < n; i++) {
		cout << B[i] << ((i == n - 1) ? "\n" : " ");
	}

	return 0;
}

void CountingSort(const vec& A, vec& B, const uint32_t k) {
	uint32_t n = A.size();
	uint32_t C[k + 1];
	memset(C, 0, sizeof(C));

	/* C[i] に i の出現数を記録する */
	for(uint32_t j = 0; j < n; j++) {
		C[A[j]]++;
	}

	/* C[i] に i 以下の数の出現数を記録する*/
	for(uint32_t i = 1; i <= k; i++) {
		C[i] += C[i - 1];
	}

	for(int32_t j = (int32_t)n - 1; j >= 0; j--) {
		B[C[A[j]] - 1] = A[j];
		C[A[j]]--;
	}
}
