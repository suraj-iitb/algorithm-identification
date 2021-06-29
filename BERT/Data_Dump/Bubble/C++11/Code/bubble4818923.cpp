#include<bits/stdc++.h>

using namespace std;


static const int MAX = 200000;

int  buble(int a[], int n) {
	int times = 0;
	bool flag = true;
	while (flag) {
		flag = false;
		for (int j = n - 1; j > 0; --j) {
			if (a[j] < a[j - 1]) {
				times++;
				swap(a[j], a[j - 1]);
				flag = true;
			}
		}
	}
	return times;
}

int main() {
	int a[MAX], n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int m = buble(a, n);
	
	for (int i = 0; i < n; ++i) {
		printf("%d", a[i]);
		if (i < n - 1)printf(" ");
	}
	printf("\n%d\n",m);
	
	return 0;
}
