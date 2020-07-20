#include <iostream>
#include <vector>
using namespace std;

int cnt;

void bubbleSort(vector<int>& a, int n) {
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (int j = n - 1; j > 0; j--) {
			if (a[j] < a[j - 1]) {
				swap(a[j], a[j - 1]);
				cnt++;
				flag = true;
			}
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
	bubbleSort(a, n);
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
