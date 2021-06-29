#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int *array = new int[n];
	for (int i = 0;i < n;i++) {
		cin >> array[i];
	}

	for (int i = 0;i < n;i++) {
		if(i<n-1)cout << array[i] << ' ';
		else cout << array[i] <<endl;
	}
	for (int i = 1;i < n;i++) {
		int v = array[i];
		int j = i - 1;
		while (j>=0 && array[j]>v) {
			array[j + 1] = array[j];
			j--;
		}
		array[j+1] = v;
		for (int k = 0;k < n;k++) {
			if (k<n - 1)cout << array[k] << ' ';
			else cout << array[k] << endl;
		}
	}

    return 0;
}
