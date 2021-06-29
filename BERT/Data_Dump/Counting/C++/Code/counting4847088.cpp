#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 2000001
int A[MAX] = { 0 }, B[MAX] = { 0 }, C[10001] = { 0 };
int n;
void CountingSort(int k) {
	for (int i = 0; i < k ; i++)
		C[i] = 0;
	for (int j = 1; j <= n; j++)
		C[A[j]]++;
	for (int i = 1; i <= k; i++)
		C[i] = C[i] + C[i - 1];
	for (int j = n; j >= 1; j--)
	{
		B[C[A[j]]] = A[j];
		C[A[j]]--;
	}
}
int main() {

	cin >> n;
	for (int i = 1; i <= n; i++)cin >> A[i];
	CountingSort(10001);
	for (int i = 1; i <= n; i++) {
		if (i>1)cout << ' ';
		cout << B[i];
	}
	cout << endl;
	return 0;
}
