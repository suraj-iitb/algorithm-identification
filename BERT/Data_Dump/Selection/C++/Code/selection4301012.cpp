#include <stdio.h>

int main()
{
    int len;
    scanf("%d", &len);

    int array[100];
    for (int i=0;i<len;i++) {
        scanf("%d", &array[i]);
    }

    int tmp, count=0;
    for (int i=0;i<len;i++) {
        int minj = i;
        for (int j=i;j<len;j++) {
            if (array[j] < array[minj]) {
                minj = j;
            }
        }
        if (i != minj) {
            tmp = array[i];
            array[i] = array[minj];
            array[minj] = tmp;
            count++;
        } 

    }

    for (int i=0;i<len;i++) {
        if (i != len-1) {
            printf("%d ", array[i]);
        } else {
            printf("%d\n", array[i]);
        }
    }
    printf("%d\n", count);

    return 0;
}
