#include<stdio.h>
#include<string.h>
#define anD &&
#define oR ||
#define max(a,b) ((a)>=(b))?(a):(b)
#define min(a,b) ((a)<=(b))?(a):(b)
#define rep(i,n) for((i)=0;(i)<(n);(i)++)

void swap(int *p, int *q) {
	int tmp;
	tmp = *p;
	*p = *q;
	*q = tmp;
}

int main() {
	int n;
	scanf("%d", &n);
	int i,j,a[101] = {};
	rep(i, n) {
		scanf("%d", &a[i]);
	}
	rep(i, n) {
		rep(j, n-1) {
			printf("%d ", a[j]);
		}
		printf("%d\n", a[n-1]);
		for (j = i + 1; j > 0; j--) {
			if (a[j - 1] > a[j]) swap(&a[j - 1], &a[j]);
		}

	}
	return 0;

}
