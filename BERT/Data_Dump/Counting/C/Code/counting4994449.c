
// ABC 153-F
// 2020.1.26 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//typedef long long ll;
typedef int Int;

#define gc() getchar_unlocked()
#define pc(c) putchar_unlocked(c)

Int in() {  // 整数の入力
	Int n = 0; int c;
	do c = gc();
	while (isspace(c));
	if (c == '-') {	c = gc();
		do n = 10*n + (c & 0xf), c = gc(); while (c >= '0');
		return -n;
	}
	do n = 10*n + (c & 0xf), c = gc(); while (c >= '0');
	return n;
}

void out(int n) { // 非負整数の表示（出力）
	int i; char b[30];

	if (!n) pc('0');
	else {
		//		if (n < 0) pc('-'), n = -n;
		i = 0; while (n) b[i++] = n % 10 + '0', n /= 10;
		while (i--) pc(b[i]);
	}
}

#define INCmode   1  // 昇順ソート
//typedef long long Int;
void Usort(Int *a, int n) {
	int i, k;
#define B 8
#define BMSK 255 // (1<<8)-1
	Int t1[1 << B], t2[1 << B];
	
	Int *tmp = malloc(n * sizeof(Int));	
	for (k = 0; k < 8; ++k) {  // for 64ビット
//	for (k = 0; k < 4; ++k) {  // for 32ビット
		memset(t1, 0, sizeof(t1)), memset(t2, 0, sizeof(t2));
		for (i = 0; i < n; ++i)	t1[(a[i] >> k*B) & BMSK]++;
#if INCmode
		for (i = 0; i < BMSK; ++i) t1[i+1] += t1[i];
#else
		i = BMSK+1; while (--i) t1[i-1] += t1[i];
#endif
		i = n; while (i--) tmp[--t1[(a[i] >> k*B) & BMSK]] = a[i];
		k++;
		for (i = 0; i < n; ++i) t2[(tmp[i] >> k*B) & BMSK]++;
#if INCmode
		for (i = 0; i < BMSK; ++i) t2[i+1] += t2[i];
#else
		i = BMSK+1; while (--i) t2[i-1] += t2[i];
#endif
		i = n; while (i--) a[--t2[(tmp[i] >> k*B) & BMSK]] = tmp[i];
	}
	free(tmp);
// for (i = 0; i < n; ++i) printf("[%d] %lld\n", i, a[i]);
}

int N;
Int a[2000005];

int main()
{
	int i;
	
	N = in();
	for (i = 0; i < N; ++i) a[i] = in();
	Usort(a, N);
	out(a[0]);
	for (i = 1; i < N; ++i) pc(' '), out(a[i]);
	pc('\n');
	return 0;
}




 



