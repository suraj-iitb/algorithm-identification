#include<iostream>
using namespace std;

void bubbleSort(int a[],int n) {
	int l = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j >= i + 1; j--) {
			if (a[j] < a[j - 1]) {
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
				l++;
			}
		}
	}
	
	for (int k = 0; k < n - 1; k++)
		cout << a[k] << " ";
	cout << a[n - 1] << endl;
	cout << l<<endl;
}
int main()
{
	int n;
	int a[200];
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
			cin >> a[i];
		bubbleSort(a, n);
	}
	
    return 0;
}
