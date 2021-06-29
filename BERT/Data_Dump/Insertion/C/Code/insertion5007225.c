#include <stdio.h>

int main () {
    int n;
    int j, temp = 0;
    int a[1000] = { 0 };

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    


    for (int i = 0; i < n; i++)
    {
        temp = a[i];
        j = i-1;
        while (j >= 0 && a[j] > temp){
            a[j+1] = a[j];
            j--;
        }

            a[j+1] = temp;
    
    for (int i = 0; i < n; i++)
    {
        if (i == n-1)
        {
        printf("%d", a[i]);
        }else printf("%d ", a[i]);
    }
    printf("\n");
    }
}
