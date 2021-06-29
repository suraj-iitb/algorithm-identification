#include<bits/stdc++.h>

using namespace std;


static const int MAX = 200000;

int  SelectionSort(int a[],int n) {
	int times = 0;
	for (int i = 0; i < n; ++i){
		int k = i;
		for (int j = i + 1; j < n; ++j) {
			if (a[j] < a[k]) {
				k = j;
			}
		}
		if (a[k] != a[i]) {
			swap(a[k], a[i]);
			times++;
		}
	}
	return times;
}

int main() {
	int n;
	cin >> n;
	int a[MAX];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int t = SelectionSort(a, n);
	
	for (int i = 0; i < n; ++i) {
		printf("%d", a[i]);
		if (i < n - 1)printf(" ");
	}
	printf("\n%d\n",t);

	return 0;
}
