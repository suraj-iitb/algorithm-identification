#include <stdio.h>

int main(void)
{
    int i, j, count, data[100], v;

    scanf("%d", &count);

    for (i = 0; i < count; i++) {
        scanf("%d", &data[i]);
    }

    for (j = 0; j < count; j++) {
        printf("%d", data[j]);
        if (j < count - 1) {
            printf(" ");
        }
    }
    putchar('\n');

    for (i = 1; i < count; i++) {
        v = data[i];
        j = i - 1;
        while (j >= 0 && data[j] > v) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = v;

        for (j = 0; j < count; j++) {
            printf("%d", data[j]);
            if (j < count - 1) {
                printf(" ");
            }
        }
        putchar('\n');
    }

    return 0;
}

