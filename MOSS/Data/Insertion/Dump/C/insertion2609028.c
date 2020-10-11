#include<stdio.h>
#include<stdlib.h>
void isort(int*, int);
main()
{
    int *a, n, i;
    scanf("%d", &n);
    a = (int*)malloc(sizeof(int) * n);
    for(i = 0; i < n - 1; i++){
        scanf("%d ", &a[i]);
    }
    scanf("%d", &a[i]);
    for(i = 0; i < n - 1; i++){
            printf("%d ", a[i]);
        }
        printf("%d\n", a[i]);
    isort(a, n);
    free(a);
}
void isort(int *a, int n)
{
    int i,j, temp;
   for(i = 1; i < n; i++){
        temp = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > temp){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
        for(j = 0; j < n - 1; j++){
            printf("%d ", a[j]);
        }
        printf("%d\n", a[j]);
    }
}
