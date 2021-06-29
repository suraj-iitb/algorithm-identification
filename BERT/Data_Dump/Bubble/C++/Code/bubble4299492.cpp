#include<iostream>
using namespace std;
void BubbleSort(int a[], int n, int &sum) {
	int i, j;
	for ( i = 0; i < n; i++){
		for (j = n - 1; j > i; j--) {
			if (a[j] < a[j - 1])
			{
				swap(a[j], a[j - 1]);
				sum++;
			}
		}
	}
}
void Print(int a[], int n) {
	for (int i = 0; i < n; i++) {
		if (i > 0) cout << " ";
		cout << a[i];
	}
}
int main() {
	int n,sum=0;
	cin >> n;
	int a[105];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	BubbleSort(a, n, sum);
	Print(a, n);
	cout << endl << sum <<endl;
	
}
