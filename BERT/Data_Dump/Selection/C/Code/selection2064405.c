#include <stdio.h>

int main() {
    int a[100] = {0};
    int min;
    int number;
    int count = 0;
    int i;
    int j;
    int temp;

    scanf("%d", &number);
    for (i = 0; i < number; i++){
        scanf("%d", &a[i]);
    }

    for (i = 0; i < number; i++) {
        min = i; //????°??????´???
        for (j = i; j < number; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        
        if (a[i] > a[min]) {
            temp = a[min];
            a[min] = a[i];
            a[i] = temp;
            count++;
        }
    }
    
    for (i = 0; i < number - 1; i++) {
        printf("%d ", a[i]);
    }
    printf("%d", a[number - 1]);
    printf("\n%d\n", count);

    return 0;
}
