#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int i, j, n;
    int count = 0;
    int data[100];
    int flag;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    flag = 1;

    for (i = 0; flag; i++) {
        flag = 0;
        for (j = n - 1; j > i; j--) {
            if (data[j - 1] > data[j]) {
                swap(&data[j - 1], &data[j]);
                count++;
                flag = 1;
            }
        }
    }
    for (i = 0; i < n; i++) {
        printf("%d", data[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
    printf("%d\n", count);

    return 0;
}

void swap(int *a, int * b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubble_sort(int data[], int n)
{

}

