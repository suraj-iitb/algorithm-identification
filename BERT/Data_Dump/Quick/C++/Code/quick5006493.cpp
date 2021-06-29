#include <cstdio>
#include <iostream>
#define MAX 100000
using namespace std;

struct Card
{
	char suit;
	int value, id;
};

int partition(Card A[], int p, int r)
{
	int i, j;
	Card t, x;
	x = A[r];
	i = p - 1;
	for (j = p; j < r; j++) {
		if (A[j].value <= x.value) {
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[r]);
	return i + 1;
}

void quick_sort(Card A[], int p, int r)
{
	int q;
	if (p < r) {
		q = partition(A, p, r);
		quick_sort(A, p, q - 1);
		quick_sort(A, q + 1, r);
	}
}

int main()
{
	int n, i;
	Card A[MAX];
	bool stable = true;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s %d", &A[i].suit, &A[i].value);
		A[i].id = i;
	}
	quick_sort(A, 0, n - 1);
	for (i = 0; i < n; i++) {
		if (A[i].value == A[i - 1].value && A[i].id < A[i - 1].id) {
			stable = false;
			break;
		}
	}
	if (stable)
		printf("Stable\n");
	else 
		printf("Not stable\n");
	for (i = 0; i < n; i++)
		printf("%c %d\n", A[i].suit, A[i].value);
	return 0;
}


