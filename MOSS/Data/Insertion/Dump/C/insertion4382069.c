#include <stdio.h>

int main(void)
{
    int i, j, k, n;
    int elements[101];
    int temp;

    scanf("%d", &n);

    for (i = 0; i < n; i++){
        scanf("%d", &elements[i]);
    }
    for (i = 0; i < n; i++){
        printf("%d", elements[i]);
        if(i != n - 1) printf(" ");
    }
    putchar ('\n');
    for (i = 1; i < n; i++){
        for(j = 0; j < i; j++){
            if(elements[i] < elements[j]){
                temp = elements[i];
                elements[i] = elements[j];
                elements[j] = temp;
            }
        }
        for (k = 0; k < n; k++){
            printf("%d", elements[k]);
            if(k != n - 1) printf(" ");
        }
        putchar ('\n');
    }

    return (0);
}

