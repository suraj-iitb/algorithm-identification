#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100;

int main() {
	
	int A[MAX]; //配列
	int n = 0; //要素数受け取り

	int count = 0; //カウンター
	int v = 0; //値保存用
	bool flag = true; //フラグ

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	while (flag)
	{
		flag = false;

		for (int j = n - 1; j > 0; j--) {
			if (A[j] < A[j - 1]) {
				v = A[j];
				A[j] = A[j - 1];
				A[j - 1] = v;
				count++;
				flag = true;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (i!=0) cout << " ";
		cout << A[i];
	}

	cout << endl;
	cout << count << endl;

	return 0;
}
