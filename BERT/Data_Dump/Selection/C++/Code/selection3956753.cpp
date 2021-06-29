#include<iostream>
#include<algorithm>
using namespace std;
int sort_2(int a[], int w)
{
	int key = 0;
	for (int i = 0; i < w; i++) {
		int min = a[i]; int n = i;
		for (int j = i; j < w; j++)
		{
			if (a[j] < min)
			{
				min = a[j];
				n = j;
			}
		}
		if (n != i) {
			swap(a[i], a[n]);
			key++;
		}
	}
	return key;
}
int main(void) {
	int n;
	int a[100];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int k = sort_2(a, n);
	for (int i = 0; i < n; i++) {
		if (i > 0) cout << " ";
		cout << a[i];
	}
	cout << endl << k<<endl;
}
