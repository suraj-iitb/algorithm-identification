#include <stdio.h>

int BinarySearch(int A[], int n, int key) {
	int mid;
	int Left = 0;
	int Right = n;
	
	while (Left < Right) {
		mid = (Left + Right) / 2;
		if (A[mid] == key) {
			return 1;
		}
		if(A[mid] < key){
			Left = mid + 1;
		} else {
			Right = mid;
		}
	}
	return 0;
}

int main() {
	int i;
	int n, q;
	int S[100000], T[50000];
	int ans = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d", &S[i]);
	}

	scanf("%d", &q);
	for (i = 0; i < q; i++) {
		scanf("%d", &T[i]);
		if (BinarySearch(S, n, T[i]) == 1) ans++;
	}

	printf("%d\n", ans);

	return 0;
}
