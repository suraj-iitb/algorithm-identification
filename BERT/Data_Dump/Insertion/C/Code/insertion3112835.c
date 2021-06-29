#include <stdio.h>
 
int main(void)
{
    int n;
    int c[100];
    int v;
    int i, j;
     
    scanf("%d", &n);
     
    for (i = 0; i < n; i++){
        scanf("%d", &c[i]);
    }
     
    for (i = 1; i < n; i++){
        for (j = 0; j < n; j++){
            printf("%d", c[j]);
            if (j < n - 1){
                printf(" ");
            }
        }
        printf("\n");
        v = c[i];
        j = i - 1;
        while (j >= 0 && c[j] > v){
            c[j + 1] = c[j];
            j--;
            c[j + 1]= v;
        }
    }
     
    for (i = 0; i < n; i++){
        printf("%d", c[i]);
        if (i < n - 1){
            printf(" ");
        }
    }
    printf("\n");
    return (0);
}


