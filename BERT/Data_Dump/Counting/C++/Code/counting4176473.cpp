#include <iostream>
#include <vector>

using namespace std;


void countingsort(vector<int>& A, vector<int>& B, int k)
{
	vector<int> C;
	for (int i=0; i<=k; i++) {
		C.push_back(0);
	}

	int An = A.size();
	for (int i=0; i<An; i++) {
		C[A[i]]++;
		B.push_back(0);
	}

	for (int i=1; i<=k; i++) {
		C[i] += C[i-1];
	}

	for (int i=An; i!=0; i--) {
		B[C[A[i-1]]-1] = A[i-1];
		C[A[i-1]]--;
	}
}

int main(void)
{
	int N;
	vector<int> A;
	cin >> N;
	int max = 0;
	for (int i=0; i<N; i++) {
		int t;
		cin >> t;
		A.push_back(t);
		if (max < t) max = t;
	}

	vector<int> B;
	countingsort(A, B, max);

	for (int i=0; i<N; i++) {
		if (i != 0) cout << " ";
		cout << B[i];
	}
	cout << endl;
}
