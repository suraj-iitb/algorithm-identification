#include <iostream>
using namespace std;

int n, a[110], i, j, t;

void bubblesort() {
	for (i = 0; i < n; i++) {
		for (j=n-1; j>=i+1; j--) {
			if (a[j]<a[j-1]) {
				swap (a[j], a[j-1]);
				t++;
			}
		}
	}
}

int main () {
	cin>>n;
		for (int i=0; i<n; i++) cin>>a[i];
		bubblesort();
		for (i=0; i<n-1; i++) cout<<a[i]<< " ";
		cout<<a[n-1]<<endl;
		cout<<t<<endl;
	return 0;
}
