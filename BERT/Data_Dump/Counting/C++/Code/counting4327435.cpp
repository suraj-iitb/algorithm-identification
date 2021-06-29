#include<iostream>
using namespace std;
#define max 10000

void countingsort(int a[], int b[],int n) {
    int c[max];
	for (int i = 0; i < max; i++) {
		c[i] = 0;
	}
	
	for (int i = 0; i < n; i++) {
		c[a[i]]++;
	}
	
	for (int i = 0; i < max; i++) {
		if(i > 0) c[i] += c[i - 1];
	}

	for (int i = n-1; i > -1; i--) {
		b[c[a[i]]-1] = a[i];
		c[a[i]]--;
	}
}

int main()
{
	int n;
	cin >> n;
	int a[2000000];
	int b[2000000];

	for (int i = 0; i < 2000000; i++) {
		b[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	countingsort(a, b, n);

	for (int i = 0; i < n; i++) {
		if (i > 0) cout << " ";
		cout << b[i];
	}

	cout << endl;
	return 0;
}
