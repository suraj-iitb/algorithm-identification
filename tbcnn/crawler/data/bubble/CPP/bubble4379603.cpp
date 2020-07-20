#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int A[101];
	for (int i=0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	int flag = 1;
	int count = 0;
	while(flag) {
		flag = 0;
		for (int i=0; i < n-1; i++) {
			if (A[i] > A[i+1]) {
				int a = A[i];
				A[i] = A[i+1];
				A[i+1] = a;
				flag = 1;
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
