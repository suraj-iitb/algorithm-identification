#include<iostream>
#include<algorithm>
using namespace std;

static const int maxsize = 100;

void showSeq(int a[],int n) {
	for (int i = 0; i < n; i++) {
		if (i > 0)cout << " ";
		cout << a[i];
	}
	cout << endl;
}


int main()
{
	int N, a[maxsize];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	int num=0;
	for (int i = 0; i < N; i++) {
		for (int j = N - 1; j > i; j--) {
			if (a[j] < a[j - 1]) {
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
				num++;
			}
		}
	}
	showSeq(a, N);
	cout << num << endl;
    return 0;
}
