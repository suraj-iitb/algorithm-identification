#include <iostream>
#include <vector>
using namespace std;

int n;

void CountingSort(vector<int>& a, vector<int>& b, int k) {
	vector<int> c(k + 1);
	for (int i = 0; i <= k; i++) {
		c[i] = 0;
	}
	for (int j = 1; j <= n; j++) {
		c[a[j]]++;
	}
	for (int i = 1; i <= k; i++) {
		c[i] = c[i] + c[i - 1];
	}
	for (int j = n; j >= 1; j--) {
		b[c[a[j]]] = a[j];
		c[a[j]]--;
	}
}

int main()
{
	cin >> n;
	vector<int> a(n + 1);
	vector<int> b(n + 1);
	int max = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (max < a[i]) {
			max = a[i];
		}
	}
	CountingSort(a, b, max);
	for (int i = 1; i <= n; i++) {
		cout << b[i];
		if (i < n)
			cout << " ";
		else
		{
			cout << endl;
		}
	}

	return 0;
}
