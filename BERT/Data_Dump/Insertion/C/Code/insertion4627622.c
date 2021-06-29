#include <stdio.h>

int main(void){
    int a[100], i, j, n, tmp, k;

    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for(k = 0; k < n; k++)
    {
        if(k > 0) printf(" ");
        printf("%d", a[k]);
    }
    printf("\n");

    for (i = 1; i < n; i++)
    {
        tmp = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > tmp)
        {
            a[j + 1] = a[j];
            j--;
            a[j + 1] = tmp;
        }
        for(k = 0; k < n; k++)
        {
            if(k > 0) printf(" ");
            printf("%d", a[k]);
        }
        printf("\n");
    }
    return 0;
}
