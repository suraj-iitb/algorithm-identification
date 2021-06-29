#include <stdio.h>

int main()
{
    int len;
    scanf("%d", &len);

    int array[100];
    for (int i=0;i<len;i++) {
        scanf("%d", &array[i]);
    }

    int tmp, flag = 1, count = 0;
    while (flag) {
        flag = 0;
        for (int j=len-1;j>0;j--) {
            if (array[j] < array[j-1]) {
                tmp = array[j];
                array[j] = array[j-1];
                array[j-1] = tmp;
                flag = 1;
                count++;
            }
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
