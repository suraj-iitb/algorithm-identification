#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#define INFTY 1000000001
using namespace std;

int L[500000] = {}, R[500000] = {},cnt;
void merge(int s[], int l,int mid, int r) {
	int n1 = mid - l, n2 = r - mid;
	for (int i = 0; i < n1;i++) {
		L[i] = s[l + i];
	}
	for (int i = 0; i < n2; i++) {
		R[i] = s[mid + i];
	}
	L[n1] = R[n2] = INFTY;
	int j = 0, k = 0;
	for (int i = l;i < r; i++) {
		cnt++;
		if (L[j] <= R[k]) {
			s[i] = L[j];
			j++;
		}
		else {
			s[i] = R[k];
			k++;
		}
	}
}
void mergeSort(int s[], int l, int r) {
	if (l + 1 < r) {
		int mid = (l + r) / 2;
		mergeSort(s, l, mid);
		mergeSort(s, mid, r);
		merge(s, l, mid, r);
	}
}
int main() {
	int n, s[500000] = {};
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	int l = 0, r = n;
	cnt = 0;
	mergeSort(s, l, r);
	for (int i = 0; i < n; i++) {
		if (i) cout << " ";
		cout << s[i];
	}
	cout << endl;
	cout << cnt << endl;
}
