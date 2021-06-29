#include <cstdio>

void print_array(int* a, int n) {
    printf("%d", a[0]);
    for (int i=1; i<n; i++) { printf(" %d", a[i]); }
    printf("\n");
}

int swap(int* a, int* b) {
    if (a == b or *a == *b) { return 1; }
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return 0;
}

int selectionSort(int* a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int min_j = i;
        for (int j = i; j < n; j++) {
            if (a[j] < a[min_j]) {
                min_j = j;
            }
        }
        if (swap(&a[i], &a[min_j]) == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    int* a = new int[n];
    scanf("%d", &a[0]);
    for (int i=1; i<n; i++) { scanf(" %d", &a[i]); }

    int count = selectionSort(a, n);
    print_array(a, n);
    printf("%d\n", count);

    return 0;
}
