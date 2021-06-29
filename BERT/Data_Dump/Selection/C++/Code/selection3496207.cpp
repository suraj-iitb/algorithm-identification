#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int times = 0;

void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
	times++;
}

int main(void)
{
	int n, minj = 0;
	cin >> n;
	vector<int>A(n);
	for (int i = 0; i < n; i++)
		cin >> A[i];
	for (int i = 0; i < n; i++) {
		minj = i;
		for (int j = i + 1; j < n; j++) {
			if (A[j] < A[minj])
				minj = j;
		}
		if (i != minj)
			swap(A[minj], A[i]);
	}
	for (int i = 0; i < n; i++) {
		cout << A[i];
		if (i != n - 1)
			cout << " ";
		else
			cout << endl;
	}
	cout << times << endl;
	return 0;
}
