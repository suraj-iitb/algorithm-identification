#include <iostream>
#include <vector>
using namespace std;

void trace (vector<int> a, int n) {
	for (int i = 0; i < n; i++) {
		if (i > 0) cout << ' ';
		cout << a.at(i);
	}
	cout << endl;
}

int main () {
	int n;
    cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a.at(i);
	}

	trace(a, n);

	for (int i = 1; i < n; i++) {
		int tmp = a.at(i);

		int j = i - 1;
		for (j; j >= 0; j--) {
			if (a.at(j) > tmp) {
				a.at(j + 1) = a.at(j);
			} else {
				a.at(j + 1) = tmp;
				break;
			}
			
			if (j == 0) a.at(j) = tmp;
		}
		
		trace(a, n);
	}

	return 0;
}

