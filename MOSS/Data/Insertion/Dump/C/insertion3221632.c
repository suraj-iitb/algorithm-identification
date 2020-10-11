#include <stdio.h>
/*
    https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_A
*/

void insertionSort(int arr[], int len);
void show(int arr[], int len);

int main(int argc, char const *argv[])
{
    int len;
    scanf("%d", &len);

    int arr[1000] = {0};
    for (int i = 0; i < len; ++i)
        scanf("%d", &arr[i]);

    insertionSort(arr, len);

    return 0;
}

void insertionSort(int arr[], int len)
{
    int j;
    int v;
    for (size_t i = 1; i < len; i++)
    {
        show(arr, len);

        v = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > v)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = v;
    }
    show(arr, len);
}

void show(int arr[], int len)
{
    for (size_t i = 0; i < len; i++)
    {
        printf("%d", arr[i]);
        if (i != len - 1)
            printf(" ");
        else
            printf("\n");
    }
}
