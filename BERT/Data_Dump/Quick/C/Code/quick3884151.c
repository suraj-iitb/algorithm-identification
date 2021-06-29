#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Card {
    char suit;
    int number;
    int pos;
};

static inline void Swap(struct Card* x, struct Card* y) {
    struct Card t = *x;
    *x = *y;
    *y = t;
}

static int Partition(struct Card A[], int p, int r) {
    int x = A[r].number;
    int i = p - 1;

    for ( int j = p; j < r; j++ ) {
        if ( A[j].number <= x ) {
            i = i + 1;
            Swap(&A[i], &A[j]);
        }
    }
    Swap(&A[i+1], &A[r]);

    return i + 1;
}

static void QuickSort(struct Card A[], int p, int r) {
    if ( p < r ) {
        int q = Partition(A, p, r);
        QuickSort(A, p, q-1);
        QuickSort(A, q + 1, r);
    }

    return;
}

static int IsStable(const struct Card A[], int n) {
    int i;
    struct Card last = A[0];

    for ( i = 1; i < n; i++ ) {
        if ( last.number == A[i].number ) {
            if ( last.pos > A[i].pos ) {
                return 0;
            }
        }
        last = A[i];
    }

    return 1;
}

int main(void) {
    int i;
    int n;
    struct Card *A;

    scanf("%d\n", &n);
    A = malloc(sizeof(struct Card) * n);

    for ( i = 0; i < n; i++ ) {
        int d;
        char s[2];
        scanf("%s %d", s, &d);
        A[i].suit   = s[0];
        A[i].number = d;
        A[i].pos    = i;
        (void)fgetc(stdin);
    }

    QuickSort(A, 0, n - 1);

    printf("%s\n", IsStable(A, n) ? "Stable": "Not stable");
    for ( i = 0; i < n; i++ ) {
        printf("%c %d\n", A[i].suit, A[i].number);
    }

    free(A);

    return 0;
}

