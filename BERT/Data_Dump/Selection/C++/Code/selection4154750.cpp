#include <bits/stdc++.h>
using namespace std;

// Function Declaration
void selectionSort(int*, int);

// Grobal variables
int ans = 0;

int main(void) {
	int n;
	cin >> n;
	int a[105];
	for(int i = 0; i < n; i++) cin >> a[i];
	selectionSort(a, n);
	for(int i = 0; i < n - 1; i++) cout << a[i] << " ";
	cout << a[n-1] << endl;
	cout << ans << endl;
	return 0;
}

void selectionSort(int* a, int n){
	for(int i = 0; i < n; i++){
		int minj = i;
		for(int j = i; j < n; j++){
			if(a[j] < a[minj]) minj = j;
		}
		int tmp = a[i];
		a[i] = a[minj];
		a[minj] = tmp;
		if(i != minj) ++ans;
	}
	return;
}

