#include <stdio.h>

typedef struct _card {
	int number;
	char suit;
} CARD;

CARD A[100000], I[100000];
char inputs[1000000];
char *ptr = inputs;

void exchange(CARD *a, CARD *b);
int Partition(CARD A[], int p, int r);
void Quicksort(CARD A[], int p, int r);

int nextInt(void) {
	int v = 0;
	while (*ptr < '0' || *ptr > '9') ++ptr;
	while (*ptr >= '0' && *ptr <= '9') {
		v = v * 10 + (int)(*ptr - '0');
		++ptr;
	}
	return v;
}

char nextSuit(void) {
	while (*ptr < 'A' || *ptr > 'Z') ++ptr;
	return *ptr;
}

int main(void) {
	int n;
	int stable = 1;
	int i, j, c, d;
	
	fread(inputs, sizeof(char), 1000000, stdin);
	
	n = nextInt();
	
	for (i = 0; i < n; ++i) {
		A[i].suit = nextSuit();
		A[i].number = nextInt();
		I[i] = A[i];
	}
	
	Quicksort(A, 0, n - 1);
	
	for (i = 0; i < n; ++i) {
		if (i == 0) {
			c = 0;
		} else if (A[i].number != A[i - 1].number) {
			c = 0;
		} else {
			++c;
		}
		d = 0;
		for (j = 0; j < n; ++j) {
			if (I[j].number == A[i].number) {
				if (c == d) {
					if (I[j].suit != A[i].suit) {
						stable = 0;
					}
					break;
				}
				++d;
			}
		}
		if (stable == 0) {
			break;
		}
	}
	
	if (stable == 1) {
		puts("Stable");
	} else {
		puts("Not stable");
	}
	
	for (i = 0; i < n; ++i) {
		printf("%c %d\n", A[i].suit, A[i].number);
	}
	
	return 0;
}

void exchange(CARD *a, CARD *b) {
	CARD t = *a;
	*a = *b;
	*b = t;
}

int Partition(CARD A[], int p, int r) {
	CARD x = A[r];
	int i = p - 1;
	int j;
	for (j = p; j < r; ++j) {
		if (A[j].number <= x.number) {
			++i;
			exchange(&A[i], &A[j]);
		}
	}
	exchange(&A[i + 1], &A[r]);
	return i + 1;
}

void Quicksort(CARD A[], int p, int r) {
	int q;
	if (p < r) {
		q = Partition(A, p, r);
		Quicksort(A, p, q - 1);
		Quicksort(A, q + 1, r);
	}
}
