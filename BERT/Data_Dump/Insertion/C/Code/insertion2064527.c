#include <stdio.h>

int main() {
    int a[1001] = {0};
    int number;
    int i, j, k;
    int temp;

    scanf("%d", &number);
    for (i = 0; i < number; i++){
        scanf("%d", &a[i]);
    }

    for (j = 0; j < number - 1; j++) {
        printf("%d ", a[j]);
    }
    printf("%d\n", a[number - 1]);

    for (i = 1; i < number; i++) {
        for (j = 0; j < i; j++) {
            if (a[i] < a[j]) {
                for (k = i; k > j; k--) {
                    temp = a[k];
                    a[k] = a[k - 1];
                    a[k - 1] = temp;
                }
                break;
            }
        }
        
        for (j = 0; j < number - 1; j++) {
            printf("%d ", a[j]);
        }
        printf("%d\n", a[number - 1]);
    }
   
    return 0;
}
