#include <cstdio>

const int mxn = 105;

int n, a[mxn], cnt = 0;

inline void swap(int &x, int &y) {
	int z;
	z = x;
	x = y;
	y = z;
	++cnt;
}

signed main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
		
	// selection sort
	for (int i = 0; i < n; ++i) {
		int mini = i;
		
		for (int j = i; j < n; ++j)
			if (a[j] < a[mini])
				mini = j;
		
		if (i != mini)
			swap(a[i], a[mini]);
	}
	
	// print array
	for (int i = 0; i < n - 1; ++i)
		printf("%d ", a[i]);
	printf("%d\n", a[n - 1]);
	
	printf("%d\n", cnt);
		
	return 0;
}
