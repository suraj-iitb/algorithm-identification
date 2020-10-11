#include <stdio.h>

#define VAL_NUM (100)

int main (void) {
        int flag = 0;
        int array[VAL_NUM];
        int val_num;
        int i, j;
        int a;

        scanf("%d", &val_num);

        for (i = 0; i < val_num; i++)
                scanf("%d", &array[i]);

        for (i = 0; i < val_num; i++) {
                for (j = 1; j < val_num; j++) {
                        if (array[j] < array[j-1]) {
                                a = array[j];
                                array[j] = array[j-1];
                                array[j-1] = a;
                                flag++;
                        }
                }
        }

        printf("%d", array[0]);
        for (i = 1; i < val_num; i++)
                printf(" %d", array[i]);
        printf("\n%d\n", flag);

        return 0;
}

