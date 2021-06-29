#include <stdio.h>

void insertion_sort(int a[], int n)
{
    int i, tmp;
    for(i = 0; i < n-1; i++)
    	printf("%d " ,a[i]);
    printf("%d\n", a[n-1]);
    for (i = 1; i < n; i++){
        int j = i;
        while (j >= 1 && a[j - 1] > a[j]) {
            tmp = a[j-1];
            a[j-1] = a[j];
            a[j] = tmp;
            j--;
        }
        for (j = 0; j < n-1; j++)
            printf("%d " , a[j]);
        printf("%d\n", a[n-1]);
    }
}

int main(void)
{
    int n, i;
    
    scanf("%d", &n);
    int a[100];
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    insertion_sort(a, n);
    return 0;
}
