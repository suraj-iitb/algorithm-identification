#include <stdio.h>
#include <string.h>
 
int main(void)
{
    int n;
    int array[100] = {};
    int count = 0;
    int i, j;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    // bubble sort
    int flag = 1;
    i = 0;

    while (flag) {
        flag = 0;
        for (j = n-1; j > 0; j--) {
            if (array[j] < array[j-1]){
                int tmp = array[j];
                array[j] = array[j-1];
                array[j-1] = tmp;
                flag = 1;
                count++;
            }
        }
        i++;
    }

    for (i = 0; i < n; i++) {
        printf("%d", array[i]);
        if (i != (n-1)) printf(" ");
    }
    printf("\n%d\n", count);

    return 0;
}
