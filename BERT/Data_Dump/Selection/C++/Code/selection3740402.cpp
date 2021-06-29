#include<iostream>
using namespace std;

void selectSort(int a[], int n) {
	int mini,temp;
	int l = 0;
	for (int i = 0; i < n; i++) {
		mini = i;
		for (int j = i; j < n; j++) {
			if (a[j] < a[mini])
				mini = j;
		}
		if (mini != i) {
			temp = a[mini];
			a[mini] = a[i];
			a[i] = temp;
			l++;
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
		selectSort(a, n);
	}
	
    return 0;
}

