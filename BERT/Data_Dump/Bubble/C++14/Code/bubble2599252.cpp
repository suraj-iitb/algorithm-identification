#include <cstdio>

const int mxn = 105;

int n, a[mxn], cnt = 0;

inline int swap(int &x, int &y) {
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
	
	// bubble sort
	for (bool flag = true; flag; ) {
		flag = false;
		
		for (int i = n - 1; i > 0; --i)
			if (a[i] < a[i - 1])
				swap(a[i], a[i - 1]), flag = true;
	}
	
	// print array
	for (int i = 0; i < n - 1; ++i)
		printf("%d ", a[i]);
	printf("%d\n", a[n - 1]);
	
	printf("%d\n", cnt);
	
	return 0;
}
