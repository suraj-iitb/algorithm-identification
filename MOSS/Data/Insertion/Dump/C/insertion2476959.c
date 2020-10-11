#include <stdio.h>
#include <stdlib.h>

void
insertionSort(int *data, int size)
{
    int i;
    int j;
    int key;

    for (i=1; i<size; ++i) {
        key = data[i];
        j = i - 1;
        while ((j>=0) && (data[j]>key)) {
            data[j+1] = data[j];
            --j;
        }
        data[j+1] = key;
        for (j=0; j<size-1; ++j) {
            printf("%d ", data[j]);
        }
        printf("%d\n", data[j]);
    }

}

int main(int argc, int *argv[])
{
    int size;
    int *data;
    int i;

    scanf("%d", &size);
    //printf("%d\n", size);
    data = malloc(size * sizeof(int));
    for (i=0; i<size; ++i) {
        scanf("%d", &data[i]);
    }

    for (i=0; i<size-1; ++i) {
         printf("%d ", data[i]);
    }
    printf("%d\n", data[i]);

    insertionSort(data, size);

    return 0;
}
