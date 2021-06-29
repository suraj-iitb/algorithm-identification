#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define AMAX 10000

int main(){

	int n;
	cin >> n;
	int* A = new int[n];
	for (int i = 0; i < n; i++) cin >> A[i];

	int* B = new int[n];
	int* C = new int[AMAX + 1];

	for (int i = 0; i < AMAX + 1; i++) C[i] = 0;
	for (int i = 0; i < n; i++) C[A[i]]++;
	for (int i = 1; i < AMAX + 1; i++) C[i] += C[i - 1];
	for (int i = n - 1; i >= 0; i--) B[--C[A[i]]] = A[i];

	for (int i = 0; i < n; i++) cout << (i == 0 ? "" : " ") << B[i];
	cout << endl;

	delete[] A;
	delete[] B;
	delete[] C;

	return 0;
}
