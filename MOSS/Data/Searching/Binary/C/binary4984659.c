#include <stdio.h>
#include <stdlib.h>

void disp_array(int* vec, int size) {
    for (int i = 0; i < size - 1; i++) {
        printf("%d ", *(vec + i));
    }
    printf("%d\n", *(vec + size - 1));
    return;
}

int binary_search(int* vec, int size, int key) {
    int left = 0;
    int right = size;
    while (left < right) {
        int mid = (left + right)/2;
        if (*(vec + mid) == key) {
            return 1;
        }
        else if (key < *(vec + mid)) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return 0;
}



int main(void) {
    int n;
    scanf("%d", &n);
    int* s;
    s = malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        scanf("%d", s + i);
    }

    int q;
    scanf("%d", &q);
    int* t;
    t = malloc(sizeof(int)*q);
    for (int i = 0; i < q; i++) {
        scanf("%d", t + i);
    }

    int count = 0;

    for (int i = 0; i < q; i++) {
        count += binary_search(s, n, *(t + i));
    }

    printf("%d\n", count);

    free(s);
    free(t);

    return 0;
}

