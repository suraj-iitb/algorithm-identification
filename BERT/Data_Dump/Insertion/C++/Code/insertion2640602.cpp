#include <iostream>
#include <algorithm>
using namespace std;

int n, a[110] , i, j, k;

void insertsort() {
	for (i = 1; i<n; i++) {
		int key = a[i];
		j = i - 1;
		while (j>=0 && a[j]>key) {
			a[j+1]=a[j];
			j--;
			}
		a[++j]=key;

		for (k = 0; k < n; k++) {
			if (k == n - 1) { cout << a[k] << endl;
			}
		else cout << a[k] << " ";
		}
	}
}

int main(){
	cin >> n;
	for (i = 0; i < n; i++)	cin >> a[i];
	for (k=0; k<n; k++) {
		if (k == n - 1) { cout << a[k] << endl; }
		else cout << a[k] << " ";
	}
	insertsort();

return 0;
}
