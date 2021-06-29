#include <iostream>
#include <vector>
using namespace std;

int main() 
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}

	for (int i = 0; i < n; ++i) {
		cout << a[i] ;
		if (i != n - 1) {
			cout << " ";
		}
	}
	cout << endl;

	for (int i = 1; i < n; ++i) {
		int v = a[i];
		int j = i - 1;
		while ( 0 <= j && v < a[j])
		{
			a[j + 1] = a[j];
			--j;
		}
		a[j + 1] = v;
		for (int k = 0; k < n; ++k) {
			cout << a[k];
			if (k != n - 1) {
				cout << " ";
			}
		}
		cout << endl;
	}

	return 0;
}
