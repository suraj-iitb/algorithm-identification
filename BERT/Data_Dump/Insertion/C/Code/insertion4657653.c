#include <stdio.h>

#include <stdlib.h>

int main() {
    int i, j, k, key;
    int array_num = 0;
    scanf("%d", &array_num);

    //dynamic scan
    int* array;
    array = (int*)malloc(array_num * sizeof(int));
    for (i = 0; i != array_num; i++) {
        scanf("%d", &array[i]);
    }

    //initial print
    for (k = 0; k < array_num; k++) {
        if (k == array_num - 1)printf("%d\n", array[k]);
        else printf("%d ", array[k]);
    }

    for (i = 1; i < array_num; i++) {

        //insertion sort
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;

        //printing
        for (k = 0; k < array_num; k++) {
            if (k == array_num - 1)printf("%d\n", array[k]);
            else printf("%d ", array[k]);
        }
    }

    return 0;

}

