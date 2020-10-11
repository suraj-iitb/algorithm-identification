#include <stdio.h>
void insertionSort(int a[], int num);
int main()
{
    int num, i;
    int a[1000];
    scanf("%d", &num);
    for(i = 0;i<num;i++){
        scanf("%d",&a[i]);
    }
    for (i = 0; i < num-1; i++)
        {
            printf("%d ", a[i]);
        }
        printf("%d\n",a[num-1]);
    insertionSort(a, num);
    return 0;
}
void insertionSort(int a[], int num)
{
    int v, i, j;
    for (i = 1; i < num; i++)
    {
        v = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > v)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        for (j = 0; j < num-1; j++)
        {
            printf("%d ", a[j]);
        }
        printf("%d\n",a[num-1]);
    }
}
