#include <iostream>
#include <string>
#include <vector>

using namespace std;
int MAX = 10001;

void countingSort(const vector<int>& A, vector<int>& B, int K) {
	const size_t n = A.size();
	B.resize(n, 0);
	vector<int> C(K, 0);
	for (auto& i : A) ++( C.at(i) );
	for (size_t i = 1; i != K; ++i) C.at(i) += C.at(i - 1);
	for (int i = n - 1; i != -1; --i) B.at(--C.at(A.at(i))) = A.at(i);
}

int main()
{
	int n;
	cin >> n;
	vector<int> A(n);
	for (auto& i : A) cin >> i;
	vector<int> B;
	countingSort(A, B, MAX);
	cout << B.front();
	for (int i = 1; i != n; ++i) cout << " "<<B.at(i);
	cout << endl;


	return 0;
}
