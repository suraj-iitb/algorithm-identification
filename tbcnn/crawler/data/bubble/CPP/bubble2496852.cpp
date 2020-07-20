#include<cstdio>
#include<iostream>
#include<algorithm>
#include<functional>
#include<string>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

int bubble_sort(int *a, int n)
{
	bool flag = true;
	int cou = 0;
	while (flag) {
		flag = false;
		for (int j = n - 1; j >= 1; j--) {
			if (a[j] < a[j - 1]) {
				int k = a[j];
				a[j] = a[j - 1];
				a[j - 1] = k;
				flag = true;
				cou++;
			}
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
	int ans = bubble_sort(a, n);

	for (int i = 0; i < n-1; i++) {
		cout << a[i] << " ";
	}
	cout << a[n - 1] << endl;
	cout << ans << endl;

	return 0;
}
