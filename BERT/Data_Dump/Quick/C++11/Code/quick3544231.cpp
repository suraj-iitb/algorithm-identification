#include"bits/stdc++.h"
using namespace std;

struct card {
	char mrc;
	int num;
	int stable;
};

int Partition(vector<card>& A, int p, int r)
{
	int i = p - 1;
	int x = A.at(r).num;

	for (int j = p; j < r; j++)
	{
		if (A.at(j).num <= x)
		{
			i++;
			swap(A.at(i), A.at(j));
		}
	}
	swap(A.at(i + 1), A.at(r));

	return i + 1;
}

void QuickSort(vector<card>& A, int p, int r)
{
	if (p >= r) return;

	int	q = Partition(A, p, r);
	QuickSort(A, p, q - 1);
	QuickSort(A, q + 1, r);

	return;
}

void checkStable(vector<card>& A)
{
	bool flag = true;
	for (int i = 0; i < A.size() - 1; i++)
	{
		if (A.at(i).num != A.at(i + 1).num) continue;
		if (A.at(i).stable >= A.at(i + 1).stable) flag = false;
	}

	if (flag) cout << "Stable" << endl;
	else cout << "Not stable" << endl;
}

void print(vector<card>& A)
{
	for (int i = 0; i < A.size(); i++) cout << A.at(i).mrc << " " << A.at(i).num << endl;
}

int main(void)
{

	int N;
	cin >> N;
	vector<card> A(N);
	for (int i = 0; i < N; i++)
	{
		cin >> A.at(i).mrc >> A.at(i).num;
		A.at(i).stable = i;
	}

	QuickSort(A, 0, N - 1);

	checkStable(A);
	print(A);


	return 0;
}
