#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int n;
int A[2000001];
int B[2000001];
int C[10001];

void countingSort(int A[], int B[], int k) {
	for (int i = 0; i <= k; i++)
		C[i] = 0;

	for (int i = 0; i < n; i++) {
		C[A[i]]++;
	}

	for (int i = 1; i <= k; i++) {
		C[i] = C[i] + C[i - 1];
	}

	for (int j = 0; j < n; j++) {
		B[C[A[j]]] = A[j];
		C[A[j]]--;
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	countingSort(A, B, 10000);
	for (int i = 1; i <= n; i++) {
		if (i > 1) cout << " "; 
		cout << B[i];
	}
	cout << endl;
}

