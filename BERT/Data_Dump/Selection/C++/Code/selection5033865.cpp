#include <stdio.h>
#include <algorithm>
using namespace std;

int n;

void print(int A[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (i)
            printf(" ");
        printf("%d", A[i]);
    }
	putchar('\n');
}

int seletion_sort(int A[], int n) {
    int i, j, minj, cnt = 0, t;
    for (i = 0; i < n - 1; i++) {
        minj = i;
        for (j = i; j < n; j++) {
            if (A[j] < A[minj]) 
                minj = j;
        }
		t = A[i]; A[i] = A[minj]; A[minj] = t;
		if (i != minj)
        	cnt++;
    }
    return cnt;
}

int main() {
    int i, A[100], cnt;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &A[i]);
    cnt = seletion_sort(A, n);
	print(A, n);
	printf("%d\n", cnt);

    return 0;
}

