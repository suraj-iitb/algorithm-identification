#include <iostream>
#define RANGE 150
using namespace std;

int num[RANGE];

void swap(int a, int b) {
	int t = num[a];
	num[a] = num[b];
	num[b] = t;
}

int main() {
	int len, ans = 0;
	
	cin >> len;
	for (int i = 0; i < len; i++)	cin >> num[i];

	for (int i = 0; i < len; i++)	for (int j = len - 1; j > i; j--) {
		if (num[j - 1] > num[j]) {
			swap(j - 1, j);
			ans++;
		}
	}

	for (int i = 0; i < len; i++) {
		if (i)	cout << " ";
		cout << num[i];
	}
	cout << endl << ans << endl;

	return 0;
}
