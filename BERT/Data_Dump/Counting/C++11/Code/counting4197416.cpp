#pragma warning (disable :4996)
#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int N = 2e6 + 10;

int n;
int A[N], B[N], C[N];
void CountingSort(int A[], int B[], int k) {
	for (int i = 0; i <= k; i++) C[i] = 0;
	for (int i = 1; i <= n; i++) C[A[i]]++;
	int flag = 0;
	for (int i = 0; i <= k; i++) {
		if (C[i]) {
			while (C[i]--) {
				if (!flag) printf("%d", i);
				else printf(" %d", i);
				flag = 1;
			}
		}
	}
	printf("\n");
}
int main() {
	int k = -1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
		k = max(k, A[i]);
	}
	CountingSort(A, B, k);

	return 0;
}
