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

char buf[20]; int w;
void mypr(int n)
{
	w = 0;
	if (!n) { buf[w++] = '0'; return; }
	while (n) buf[w++] = n%10 + '0', n/=10;
}

#define MAX_N 10000
int f[MAX_N+2];

int main()
{
	int N, i, j, c;

	N = in();
	for (i = 0; i < N; i++) f[in()]++;
	for (i = 0; ; i++) if (c = f[i]) break;
	mypr(i); j = w; while (j--) pc(buf[j]);
	while (--c) { pc(' '); j = w; while (j--) pc(buf[j]); }
	while (++i <= MAX_N) if (c = f[i]) {
		mypr(i); 
		while (c--) { pc(' '); j = w; while (j--) pc(buf[j]); }
	}
	pc('\n');
	return 0;
}

