#include <iostream>
#include <vector>
using namespace std;

int cnt;

void selectionSort(vector<int>& a, int n) {
	for (int i = 0; i < n; i++) {
		int minj = i;
		for (int j = i; j < n; j++) {
			if (a[j] < a[minj])
				minj = j;
		}
		if (i != minj) {
			swap(a[i], a[minj]);
			cnt++;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	selectionSort(a, n);
	for (int i = 0; i < n; i++) {
		cout << a[i];
		if (i < n - 1)
			cout << " ";
		else
			cout << endl;
	}
	cout << cnt << endl;
	return 0;
}
