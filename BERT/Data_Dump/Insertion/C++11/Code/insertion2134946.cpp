#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	void printList(int ar[], int n);
	ios::sync_with_stdio(false);
	int cnt;
	cin >> cnt;
	int ar[cnt];
	for (int i = 0; i < cnt; i++)
		cin >> ar[i];

	for (int i = 0; i < cnt; i++) {
		int v = ar[i];
		int j = i - 1;
		while (j >= 0 && ar[j] > v) {
			ar[j + 1] = ar[j];
			j--;
		}
		ar[j + 1] = v;
		printList(ar, cnt);
	}
	return 0;
}

void printList(int ar[], int n) {
	for (int i = 0; i < n; i++) {
		if(i > 0) cout << " ";
		cout << ar[i];
	}
	cout<< endl;
}
