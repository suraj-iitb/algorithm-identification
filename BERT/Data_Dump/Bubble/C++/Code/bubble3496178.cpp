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
	int n;
	cin >> n;
	vector<int>A(n);
	for (int i = 0; i < n; i++)
		cin >> A[i];
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= i + 1; j--) {
			if (A[j] < A[j - 1])
				swap(A[j], A[j - 1]);
		}
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
