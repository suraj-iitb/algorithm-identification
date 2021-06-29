#include"bits/stdc++.h"
using namespace std;

void countingSort(vector<int>& A, vector<int>& B, int k)
{
	vector<int> C(10005, 0);

	for (int i = 0; i < A.size(); i++) C.at(A.at(i))++;

	for (int i = 1; i <= k; i++) C.at(i) = C.at(i) + C.at(i - 1);

	for (int i = A.size() - 1; i >= 0; i--)
	{
		B.at(C.at(A.at(i)) - 1) = A.at(i);
		C.at(A.at(i))--;
	}
}

int main(void)
{

	int N;
	cin >> N;
	vector<int> A(N), B(N);

	for (int i = 0; i < N; i++) cin >> A.at(i);

	countingSort(A, B, 10000);

	for (int i = 0; i < B.size(); i++)
	{
		if (i) cout << " ";
		cout << B.at(i);
	}
	cout << endl;

	return 0;
}
