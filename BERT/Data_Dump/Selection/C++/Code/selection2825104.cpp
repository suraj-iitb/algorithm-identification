#include <iostream>
using namespace std;


int selectionSort(int a[], int n) {
	int cnt = 0;

	for (int i = 0;i < n;i++) {
		int minj = i;

		for (int j = i;j < n;j++) {
			if (a[j] < a[minj]) minj = j;
		}

		if (i != minj) {
			swap(a[i], a[minj]);
			cnt++;
		}
	}

	return cnt;
}


int main()
{
	int n, t, a[100];
	cin >> n;

	for (int i = 0;i < n;i++) cin >> a[i];

	t = selectionSort(a, n);

	for (int i = 0;i < n;i++) {
		cout << a[i];
		if (i == n - 1) cout << endl;
		else cout << " ";
	}

	cout << t << endl;
    return 0;
}

