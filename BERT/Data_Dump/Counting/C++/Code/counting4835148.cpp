#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<list>
#include<numeric>
#include<queue>
#include<stack>
#include<stdio.h>
#include<string>
#include<vector>

using namespace std;

const int SENTINEL = 2000000000;
const double PI = acos(-1);

void print_array(int n, int a[]) {
	for (int i = 0; i < n; i++) {
		if (i > 0) cout << " ";
		cout << a[i];
	}
	cout << endl;
}

void print_list(list<int> lst) {
	list<int>::iterator itr;
	for (itr = lst.begin(); itr != lst.end(); itr++) {
		if (itr != lst.begin()) cout << " ";
		cout << *itr;
	}
	cout << endl;
}

const int MAX = 2000000;
const int K_MAX = 10001;
int A[MAX];
int B[MAX];
int C[K_MAX];

void countingsort(int n, int a[], int b[], int k) {
	for (int i = 0; i < k; i++) {
		C[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		C[a[i]]++;
	}

	for (int i = 1; i < k; i++) {
		C[i] = C[i] + C[i - 1];
	}

	for (int i = n - 1; i >= 0; i--) {
		b[C[a[i]] - 1] = A[i];
		C[a[i]]--;
	}
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];

	countingsort(n, A, B, K_MAX);
	//print_array(n, A);
	print_array(n, B);
	//print_array(K_MAX, C);

	return 0;
}

