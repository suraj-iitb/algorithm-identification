#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int A[101];
	int count = 0;
	for (int i=0; i < n; i++) {
		scanf("%d", &A[i]);
	};
	int flag = 0;
	for (int i=0; i < n; i++) {
		int minj = i;
		for (int j=i+1; j < n; j++) {
			if (A[j] < A[minj]) {
				minj = j;
				flag = 1;
			}
		}
		if (flag) {
			if (A[i] != A[minj]) {
				swap(A[i], A[minj]);
				count++;
			}
		}
	}	
	for (int i=0; i < n; i++) {
		if (i == n-1) {
			printf("%d", A[i]);
		} else {
			printf("%d ", A[i]);
		}
	}
    printf("\n%d\n", count);
}
