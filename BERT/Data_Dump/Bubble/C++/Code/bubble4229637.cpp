
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
void bubbleSort(vector<int> a, int n) {
	bool flag = true;
	int cnt = 0;
	while (flag) {
		flag = 0;
		for (int j = n - 1;j > 0;j--) {
			if (a[j] < a[j - 1]) {
				int tmp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = tmp;
				flag = 1;
				cnt++;
			}
		}
	}
	trace(a, n, cnt);
}
int main(void) {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0;i < n;i++)cin >> a[i];
	bubbleSort(a, n);
	return 0;
}
