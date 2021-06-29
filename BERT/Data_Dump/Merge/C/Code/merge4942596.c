#include <stdio.h>
#include <string.h>

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
	int w;
	if (!n) { pc('0'); return; }
	w = 0; while (n) buf[w++] = n%10 + '0', n/=10;
	while (w--) pc(buf[w]);
}

#define MAX_N 500002
#define INF   0x7f7f7f7f

int a[MAX_N];
int w[MAX_N/2+2];
int cnt;

void merge_sort(int low, int high) 
{ 
	int i, j, k, p, mid; 

	if (low < high) {
		mid = (low + high) >> 1;
		merge_sort(low,   mid);
		merge_sort(mid+1, high);

cnt += high-low+1;

		p = mid-low+1;
		memcpy(w, a+low, p << 2);
		i = mid+1, j = 0; k = low;

		w[p] = INF;
		while (i <= high) {
			if (w[j] <= a[i]) a[k++] = w[j++];
			else              a[k++] = a[i++];
		}
		memcpy(a+k, w+j, (p-j) << 2);
	}
}

int main()
{
	int n, i;
	
	n = in(); for (i = 0; i < n; i++) a[i] = in();

	cnt = 0;
	merge_sort(0, n-1);

	mypr(a[0]); for (i = 1; i < n; i++) pc(' '), mypr(a[i]); pc('\n');
	mypr(cnt); pc('\n');
	return 0;
        }

