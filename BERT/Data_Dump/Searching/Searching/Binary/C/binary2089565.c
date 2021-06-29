#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<stdio.h>
#include<stdlib.h>
void BinarySearch(unsigned long long p[], unsigned long long key, unsigned long long*,unsigned long long);
int main() {
	unsigned long long n, S[100000] = { 0 }, T[50000] = { 0 }, q, i, cnt = 0;
	unsigned long long *p=S, *key=T;
	scanf("%lld", &n);
	for (i = 0; i < n; i++) scanf("%lld", p + i);
	
	scanf("%lld", &q);
	for (i = 0; i < q; i++) scanf("%lld", key + i);
	
	for (i = 0; i < q; i++) BinarySearch(p, *(key + i), &cnt,n);
	printf("%lld\n", cnt);
	return 0;
}

void BinarySearch(unsigned long long p[], unsigned long long key, unsigned long long *cnt, unsigned long long n){
	unsigned long long l,r,m;
	for (l = 0, r = n; l < r;) {
		m = (l + r) / 2;
		if (*(p + m) == key) { *(cnt) += 1; break; }
		else if (key < *(p + m)) r = m;
		else if (key > *(p + m)) l = m + 1;
	}
}
