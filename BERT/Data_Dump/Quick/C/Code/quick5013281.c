#include <stdio.h>
#include <stdlib.h>

int n;

struct card {
    char key;
    int num;
    int pri;
};

void swap(struct card* c1, struct card* c2) {
    char tempkey = c1->key;
    int tempnum = c1->num;
    int temppri = c1->pri;

    c1->key = c2->key;
    c1->num = c2->num;
    c1->pri = c2->pri;

    c2->key = tempkey;
    c2->num = tempnum;
    c2->pri = temppri;
    return;
}

int partition(struct card set[], int p, int r) {
    int x = set[r].num;
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (set[j].num <= x) {
            i++;
            swap(set + i, set + j);
        }
    }
    swap(set + i + 1, set + r);
    return i + 1;
}

void disp(struct card set[]) {
    for (int i = 0; i < n; i++) {
        printf("%c %d\n", set[i].key, set[i].num);
    }
    return;
}

void quicksort(struct card set[], int p, int r) {
    if (p < r) {
        int q = partition(set, p, r);
        quicksort(set, p, q - 1);
        quicksort(set, q + 1, r);
    }
}

int main(void) {
    scanf("%d\n", &n);
    struct card* set;
    set = malloc(sizeof(struct card)*n);
    for (int i = 0; i < n - 1; i++) {
        scanf("%c %d\n", &set[i].key, &set[i].num);
        set[i].pri = i;
    }
    scanf("%c %d", &set[n - 1].key, &set[n - 1].num);
    set[n - 1].pri = n - 1;
    quicksort(set, 0, n - 1);
    int flag = 1;
    for (int i = 0; i < n - 1; i++) {
        if (set[i].num == set[i + 1].num) {
            if (set[i].pri > set[i + 1].pri) {
                flag = 0;
                break;
            }
        }
    }
    if (flag) {
        printf("Stable\n");
    }
    else {
        printf("Not stable\n");
    }
    disp(set);
    free(set);
    return 0;
}

