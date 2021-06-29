#include <iostream>

using namespace std;

int main() {
	int u = 0, n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
	    int mini = i;
	    for (int j = i; j < n; j++) {
	        if (a[j] < a[mini]) {
	            mini = j;
	        }
	    }
	    if (i < mini) {
	        int x = a[i];
            a[i] = a[mini];
            a[mini] = x;
            u++;
	    }
	}
	for (int i = 0; i < n - 1; i++) cout << a[i] << " ";
	cout << a[n - 1] << endl << u << endl;
}


