#include <iostream>
#define RANGE 500
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

	for (int i = 0; i < len; i++) {
		int minn = i;
		//for (int j = len - 1; j > i; j--)	if (num[j] < num[minn])	minn = j;
		for (int j = i; j < len; j++)	if (num[j] < num[minn])	minn = j;

		if (minn != i) {
			swap(minn, i);
			//cout << num[minn] << "@" << i + 1 << " "<< num[i] << "@" << minn + 1 << endl;
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
