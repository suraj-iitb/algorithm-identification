#include <stdio.h>

void DispArg(int elem[], int num)
{
    int i;

    printf("%d", elem[0]);
    for (i = 1; i < num; i++) {
        printf(" %d", elem[i]);
    }
    printf("\n");

    return;
}

int main(void)
{
    int i, j, k;
    int num;
    int tmp;
    int elem[100];

    scanf("%d", &num);
    for (i = 0; i < num; i++) {
        scanf("%d", &elem[i]);
    }

    DispArg(elem, num);

    for (i = 1; i < num; i++) {
        int v = elem[i];
        for (j = i; j > 0; j--) {
            if (v < elem[j-1]) {
                elem[j] = elem[j-1];
            }
            else {
                break;
            }
        }
        elem[j] = v;
        DispArg(elem, num);
    }

    return 0;
}
