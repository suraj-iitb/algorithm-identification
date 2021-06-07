#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<stdio.h>
void LinearSearch(unsigned int p[], unsigned int key, unsigned int*,unsigned int);
int main() {
	unsigned int n, S[10000] = { 0 }, T[500] = { 0 }, q, i, cnt = 0;
	unsigned int *p, *key;
	p = S; key = T;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", p + i);
	scanf("%d", &q);
	for (i = 0; i < q; i++) scanf("%d", key + i);
	for (i = 0; i < q; i++) LinearSearch(p, *(key + i), &cnt,n);
	printf("%d\n", cnt);
	return 0;
}

void LinearSearch(unsigned int p[], unsigned int key, unsigned int *cnt, unsigned int n){
	unsigned int i;
	for (i = 0; i < n; i++) if (*(p + i) == key) { *(cnt) += 1; break; }
}
