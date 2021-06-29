
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void trace(vector<int> a, int n, int cnt) {
	for (int i = 0;i < n;i++) {
		cout << a[i];
		if (i < n - 1)cout << " ";
		if (i == n - 1) cout << endl;
	}
	cout << cnt << endl;
}
void selectionSort(vector<int> a, int n) {
	int cnt = 0;
	for (int i = 0;i < n;i++) {
		int minj = i;
		for (int j = i;j < n;j++) {
			if (a[j] < a[minj]) {
				minj = j;
			}
		}
		if (minj != i)cnt++;
		int tmp = a[i];
		a[i] = a[minj];
		a[minj] = tmp;
	}
	trace(a, n, cnt);
}
int main(void) {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0;i < n;i++)cin >> a[i];
	selectionSort(a, n);
	return 0;
}
