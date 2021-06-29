#include <stdio.h>

int main(void)
{
    int A[100];
    int n, mini, counter, temp, i, j;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    
    counter = 0;
    for (i = 0; i < n; i++){
        mini = i;
        for (j = i; j < n; j++){
            if (A[j] < A[mini]){
                mini = j;
            }
        }
        if (i != mini){
            temp = A[i];
            A[i] = A[mini];
            A[mini] = temp;
            counter++;
        }
    }
    
    for (i = 0; i < n; i++){
        if (i != 0){
            printf(" ");
        }
        printf("%d", A[i]);
    }
    printf("\n");
    printf("%d\n", counter);
    
    return (0);
}
