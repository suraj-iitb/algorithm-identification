#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int *data;
    int n, i, j;
    int swapped;
    int mini;
    int temp;

    scanf("%d", &n);
    data = malloc(n * sizeof(int));

    swapped = 0;
    for (i = 0; i < n; i++) scanf("%d", &data[i]);

    for (i = 0; i < n; i++){
        mini = i;
        for (j = i; j < n; j++){
            if (data[j] < data[mini]){
                mini = j;
            }
            
        }
        temp = data[i];
        data[i] = data[mini];
        data[mini] = temp;
        if (i != mini) swapped++;
    }

    for (i = 0; i < n - 1; i++) printf("%d ", data[i]);
    printf("%d\n", data[i]);

    printf("%d\n", swapped);
    free(data);
    return (0);
}
