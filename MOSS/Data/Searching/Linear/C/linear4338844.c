#include <stdio.h>
#include <stdlib.h>

int search(int *array, int n, int x) {
    for(int i = 0; i < n; i++) {
        if(array[i] == x) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    int n;
    scanf("%d", &n);

    int *s = malloc(n * sizeof(int));
    if(s == NULL) {
        return 1;
    }

    for(int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }

    int q;
    scanf("%d", &q);

    int *t = malloc(q * sizeof(int));
    if(t == NULL) {
        return 1;
    }

    for(int i = 0; i < q; i++) {
        scanf("%d", &t[i]);
    }

    int cnt = 0;
    for(int i = 0; i < q; i++) {
        if(search(s, n, t[i]) != -1) {
            cnt++;
        }
    }

    printf("%d\n", cnt);

    free(s);
    free(t);
    return 0;
}
