#include <cstdio>

const int mxn = 105;

int n, a[mxn];

signed main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	
	for (int i = 0; i < n; ++i) {
		// insert a[i]
		int v = a[i], p = 0;
		
		while (p < i && v > a[p])++p; 
		
		for (int j = i; j > p; --j)
			a[j] = a[j - 1];
		
		a[p] = v;
		
		// print array
		for (int j = 0; j < n - 1; ++j)
			printf("%d ", a[j]);
		printf("%d\n", a[n - 1]);
	}
	
	return 0;
}
