#include <stdio.h>

#if 1
#define gc() getchar_unlocked()
#define pc(c) putchar_unlocked(c)
#else
#define gc() getchar()
#define pc(c) putchar(c)
#endif
int in()
{
	int n = 0, c = gc();
	do n = 10*n + (c & 0xf), c = gc(); while (c >= '0');
	return n;
}

char buf[20];
void mypr(int n)
{
	int i;
	if (!n) { pc('0'); return; }
	i = 0; while (n) buf[i++] = n%10 + '0', n/=10;
	while (i--) pc(buf[i]); 
}

typedef struct { char c; int a; int id; } DATA;

int partition(DATA *a, int lo, int hi)
{
	int i, j;
	int key;
	DATA t;
	
	key = a[hi].a, i = lo-1;
	for (j = lo; j < hi; j++) {
		if (a[j].a <= key) i++, t = a[i], a[i] = a[j], a[j] = t;
	}
	t = a[++i], a[i] = a[hi], a[hi] = t;
	return i;
}

void quick_sort(DATA *a, int lo, int hi)
{
	int mi;

	if (lo < hi) {
		mi = partition(a, lo, hi);
		quick_sort(a, lo, mi-1);
		quick_sort(a, mi+1, hi);
	}
}

DATA a[100002];

int main()
{
	int N, i, f;

	N = in();
	for (i = 0; i < N; i++) {
		a[i].c = gc(), gc();
		a[i].a = in(), a[i].id = i;
	}
	quick_sort(a, 0, N-1);
	f = 0; for (i = 1; i < N; i++) {
		if (a[i-1].a == a[i].a && a[i-1].id > a[i].id) { f = 1; break; }
	}
	puts(f? "Not stable": "Stable");
	for (i = 0; i < N; i++) {
		pc(a[i].c), pc(' '), mypr(a[i].a), pc('\n');
	}
	return 0;
}

