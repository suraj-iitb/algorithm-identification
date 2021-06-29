#include <iostream>
#include <string>
//#include <algorithm>

#include <stdio.h>
using namespace std;

void swap(int &a, int &b) {
    int tmp = b;
    b = a;
    a = tmp;
}

int bubbleSort(int A[], int N) {
    int sw = 0;
    bool flag = true;
    int i = 0;
    while (flag) {
        flag = false;
        for (int j = N - 1; j > i; j--) {
            if (A[j] < A[j - 1]) {
                flag = true;
//				cout << j << " " << A[j - 1] << " " << A[j] << endl;
                swap(A[j], A[j - 1]);
//				cout << j << " " << A[j - 1] << " " << A[j] << endl;
                sw++;
            }
        }
		i++;
    }

    return sw;
}

int main(void) {
	int N;
    int sw;
	int A[100];
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
    sw = bubbleSort(A, N);


	for (int i = 0; i < N; i++) {
		if (i != 0) cout << " ";
		cout << A[i];
	}
	cout << endl;
	cout << sw << endl;
	return 0;
}

