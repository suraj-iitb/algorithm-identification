#include<iostream>
using namespace std;

const int MAX = 110;
int N;
bool flag;
int A[MAX];
int cnt;

void Swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> A[i];
	flag = true;
	int isSorted = 0;
	while (flag)
	{
		flag = false;
		for (int i = N - 1; i > isSorted; --i)
		{
			if (A[i] < A[i - 1])
			{
				Swap(A[i], A[i - 1]);
				cnt++;
				flag = true;
			}
		}
		isSorted++;
	}
	for (int i = 0; i < N; ++i)
	{
		if (i) cout << ' ';
		cout << A[i];
	}
	cout << endl;
	cout << cnt << endl;
	return 0;
}
