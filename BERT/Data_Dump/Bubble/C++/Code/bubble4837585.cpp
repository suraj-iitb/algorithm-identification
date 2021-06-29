#include<iostream>
using namespace std;

static const int MAX = 100;

void show(int* A, int n) {
	for (int i = 0; i < n; i++) {
		cout << A[i];
		if (i < n - 1) {
			cout << ' ';
		}
	}
	cout << endl;
	return;
}

int bubble_sort(int* A, int n) {
	int num = 0;
	int flag = 1;
	int i = 0;
	while (flag) {
		flag = 0;
		for (int j = n - 1; j > i; j--) {
			if (A[j] < A[j - 1]) {
				int tmp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = tmp;
				flag = 1;
				num++;
			}
		}
		i++;
		//show(A, n);
	}
	return num;
}

int main()
{
	int n;
	int A[MAX];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	//show(A, n);
	int num=bubble_sort(A, n);
	show(A, n);
	cout << num << endl;


	return 0;
}
