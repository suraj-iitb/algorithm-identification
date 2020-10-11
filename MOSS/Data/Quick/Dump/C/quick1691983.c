#include <stdio.h>

#define MAX 100000

typedef struct {
	char suit;
	int rank;
	int in;
} card;

int partition(card *, int, int);
void quickSort(card *, int, int);
void swap(card *, card *);

int main(void)
{
	int i, n, flag=1;
	card C[MAX];
	
	scanf("%d",&n);
	for (i=0; i<n; i++) {
		scanf(" %c %d", &C[i].suit, &C[i].rank);
		C[i].in = i;
	}
	
	quickSort(C, 0, n-1);
	
	for (i=0; i<n-1; i++) {
		if(C[i].rank == C[i+1].rank) {
			if(C[i].in > C[i+1].in) {
				flag = 0;
				break;
			}
		}
	}
	if(flag) printf("Stable\n");
	else printf("Not stable\n");
	for (i=0; i<n; i++) {
		printf("%c %d\n", C[i].suit, C[i].rank);
	}
	
	return 0;
}

int partition(card *C, int p, int r)
{
	int i, j, q, x;
	
	x = C[r].rank;
	i = p-1;
	for (j=p; j<r; j++) {
		if (C[j].rank <= x) {
			swap(&C[++i], &C[j]);
		}
	}
	swap(&C[++i], &C[r]);
	return i;
}

void quickSort(card *C, int p, int r)
{
	int q;
	
	if(p < r) {
		q = partition(C, p, r);
		quickSort(C, p, q-1);
		quickSort(C, q+1, r);
	}
}

void swap(card *a, card *b)
{
	card temp=*a;
	*a = *b;
	*b = temp;
}
