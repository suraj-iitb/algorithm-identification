#include <iostream>
using namespace std; 
int bubblesort(int a[], int n) {
	bool flag=1;
	int sw = 0;
	for (int i = 0; flag; i++) {
		flag = 0;
		for (int j = n - 1; j >= i + 1; j--) {
			if (a[j] < a[j - 1]){ swap(a[j], a[j - 1]);
			sw++;
			flag = 1;
}
		}
	}
	return sw;
}


int main()
{
	int a[100];
	int n;
	int sw;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sw=bubblesort(a, n);

	for (int i = 0; i < n; i++) {
		if (i > 0) cout << " ";
		cout << a[i];
	}
	cout << endl;
	cout << sw<<endl;
	
	return 0;
	
}


