#include <iostream>
#include <cmath>

using namespace std;

int Bsort(int *arr,int n) {
	bool flag = true;
	int i = 0;
	int count = 0;
	while (flag) {
		flag = false;
		for (int j=n-1; j>i; j--) {
			if (arr[j] < arr[j-1]) {
				int t = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = t;
				flag = true;
				count++;
			}
		}
		i++;
	}
	return count;
}
int main() {
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i=0; i<n; i++) {
		cin >> arr[i];
	}
	int c = Bsort(arr,n);
	for (int i=0; i<n; i++) {
		if (i) cout << " ";
		cout << arr[i];
	}
	cout << endl;
	cout << c << endl;
	return 0;
}
