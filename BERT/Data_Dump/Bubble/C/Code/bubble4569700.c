#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int *data;
    int n, i, j;
    int swapped;
    int temp;

    scanf("%d", &n);
    data = malloc(n * sizeof(int));

    swapped = 0;
    for (i = 0; i < n; i++) scanf("%d", &data[i]);
    for (i = 0; i < n; i++){
        for (j = n - 1; j > i; j--){
            if (data[j] < data[j - 1]){
                temp = data[j];
                data[j] = data[j - 1];
                data[j - 1] = temp;
                swapped++;
            }
        }
    }

    for (i = 0; i < n - 1; i++) printf("%d ", data[i]);
    printf("%d\n", data[i]);

    printf("%d\n", swapped);
    free(data);
    return (0);
}
