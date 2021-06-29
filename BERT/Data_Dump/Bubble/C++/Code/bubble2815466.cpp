#include<iostream>
#include<algorithm>

using namespace std;

int bubbleSort(int a[], int N) {
	int sw = 0;
	bool flag = 1;
	for (int i = 0;flag;i++) {
		flag = 0;
		for (int j = N - 1;j >= i + 1;j--) {
			if (a[j - 1] > a[j]) {
				swap(a[j - 1], a[j]);
				flag = 1;
				sw++;
			}
		}
	}
	return sw;
}

int main() {
	int N;
	cin >> N;
	int a[114514];
	int i, j;
	for (i = 0;i < N;i++) {
		cin >> a[i];
	}
	int sw = bubbleSort(a, N);
	for (int i = 0;i < N;i++) {
		if (i)cout << " ";
		cout << a[i];
	}
	cout << endl;
	cout << sw << endl;
	return 0;
}
