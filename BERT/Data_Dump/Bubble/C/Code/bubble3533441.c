#include <stdio.h>
void printArray(int var[], int num) {
    int i;
    for (i = 0; i < num; i++) {
        if (i > 0) printf(" ");
        printf("%d", var[i]);
    }
    printf("\n");
}

void bubbleSort(int var[], int num) {
    int i, tmp;
    int flag = 1;
    int counter = 0;
    while (flag) {
        flag = 0;
        for (i = 1; i < num; i++) {
            if (var[i] < var[i - 1]) {
                tmp = var[i];
                var[i] = var[i - 1];
                var[i - 1] = tmp;
                flag = 1;
                counter++;
            }
        }
    }
    printArray(var, num);
    printf("%d\n", counter);
}

int main(void) {
    int i, num;
    scanf("%d", &num);
    int var[num];
    for (i = 0; i < num; i++) scanf("%d", &var[i]);

    bubbleSort(var, num);

    return 0;
}
