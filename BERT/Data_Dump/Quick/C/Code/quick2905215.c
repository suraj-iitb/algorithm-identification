#include <stdio.h>
#include <stdbool.h>

#define MAX      100000
#define SENTINEL 2000000000

typedef struct Card_
{
    char suit;
    int value;
} Card;

Card L[MAX / 2 + 1];
Card R[MAX / 2 + 1];

static void merge(Card A[], int n, int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;

    for (int i = 0; i < n1; i++) {
        L[i] = A[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = A[mid + i];
    }
    L[n1].value = R[n2].value = SENTINEL;

    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        if (L[i].value <= R[j].value) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        }
    }
}

static void mergeSort(Card A[], int n, int left, int right)
{
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(A, n, left, mid);
        mergeSort(A, n, mid, right);
        merge(A, n, left, mid, right);
    }
}

static int partition(Card A[], int n, int p, int r)
{
    Card x = A[r];
    int i = p - 1;

    for (int j = p; j < r; j++) {
        if (A[j].value <= x.value) {
            i++;
            Card tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }

    i++;
    Card tmp = A[i];
    A[i] = A[r];
    A[r] = tmp;
    return i;
}

static void quickSort(Card A[], int n, int p, int r)
{
    if (p < r) {
        int q = partition(A, n, p, r);
        quickSort(A, n, p, q - 1);
        quickSort(A, n, q + 1, r);
    }
}

int main()
{
    int n;
    Card A[MAX], B[MAX];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char s[2];
        int v;
        scanf("%s %d", s, &v);
        A[i].suit = B[i].suit = s[0];
        A[i].value = B[i].value = v;
    }

    mergeSort(A, n, 0, n);
    quickSort(B, n, 0, n - 1);

    bool stable = true;
    for (int i = 0; i < n; i++) {
        if (A[i].suit != B[i].suit) {
            stable = false;
            break;
        }
    }

    if (stable) {
        printf("Stable\n");
    } else {
        printf("Not stable\n");
    }

    for (int i = 0; i < n; i++) {
        printf("%c %d\n", B[i].suit, B[i].value);
    }

    return 0;
}