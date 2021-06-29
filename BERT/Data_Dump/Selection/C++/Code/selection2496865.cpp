#include<cstdio>
#include<iostream>
#include<algorithm>
#include<functional>
#include<string>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

int selection_sort(int *a, int n)
{
	int cou = 0;
	for (int i = 0; i < n; i++) {
		int minj = i;
		for (int j = i; j < n; j++) {
			if (a[j] < a[minj]) {
				minj = j;
			}
		}
		if (i != minj) {
			int k = a[i];
			a[i] = a[minj];
			a[minj] = k;
			cou++;
		}
	}
	return cou;
}

int main()
{
	int n;
	cin >> n;
	int a[105];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int k=selection_sort(a, n);

	for (int i = 0; i < n - 1; i++) {
		cout << a[i] << " ";
	}
	cout << a[n - 1] << endl;

	cout << k << endl;

	return 0;
}
