#include <stdio.h>

#define MAX 100002
#define inf 2000000000

struct card {
	char suit;
	int value;
};


struct card L[MAX/2 + 2], R[MAX/2 + 2];

void merge(struct card A[], int n, int left, int mid, int right) {
	 int n1 = mid - left;
	 int n2 = right - mid;
	 for (int i = 0; i < n1; i++) L[i] = A[left + i];
	 for (int i = 0; i < n2; i++) R[i] = A[mid + i];
	 L[n1].value = inf;
	 R[n2].value = inf;
	 int i1 = 0, i2 = 0;
	 for (int j = left; j < right; j++) {
	 	if (L[i1].value <= R[i2].value) {
	 		A[j] = L[i1];
	 		i1 += 1;
	 	} else {
	 		A[j] = R[i2];
	 		i2 += 1;
	 	}
	 }
}


void mergesort(struct card A[], int n, int left, int right) {
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		mergesort(A, n, left, mid);
		mergesort(A, n, mid, right);
		merge(A, n, left, mid, right);
	}
}


int partion(struct card A[], int p, int r) {
	int x = A[r].value;
	int i = p - 1;
	struct card t;
	for (int j = p; j < r; j++) {
		if (A[j].value <= x) {
			i += 1;
			t = A[j];
			A[j] = A[i];
			A[i] = t;
		}
	}
	t = A[r];
	A[r] = A[i+1];
	A[i+1] = t;
	return i + 1;
}

void quicksort(struct card A[], int p, int r) {
	if (p < r) {
		int q = partion(A, p, r);
		quicksort(A, p, q-1);
		quicksort(A, q+1, r);
	}
}

int main() {
	struct card A[MAX], B[MAX];
	int n;
	char s[6];
	scanf("%d", &n);
	int value;
	bool stable = true;
	for (int i = 0; i < n; i++) {
		scanf("%s %d", s, &value);
		A[i].suit = B[i].suit = s[0];
		A[i].value = B[i].value = value;
	}

	mergesort(B, n, 0, n);
	quicksort(A, 0, n-1);

	for (int i = 0; i < n; i++) {
		if (A[i].suit != B[i].suit) {
			stable = false;
			break;
		} 
	}

	if (stable) printf("Stable\n");
	else printf("Not stable\n");
	for (int i = 0; i < n; i++) {
		printf("%c %d\n", A[i].suit, A[i].value);
	}

	return 0;
}

