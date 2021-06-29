#include <stdio.h>

int main()
{
    int len;
    scanf("%d", &len);

    int array[100];
    for (int i=0;i<len;i++) {
        scanf("%d", &array[i]);
    }

    for(int i=0;i<len;i++) {
        if (i != len-1) {
            printf("%d ", array[i]);
        } else {
            printf("%d\n", array[i]);
        }
    }

    int target;
    for (int i=1;i<len;i++) {

        target = array[i];
        int j = i - 1;
        while (j>=0 & array[j] > target) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = target;
        
        for(int i=0;i<len;i++) {
            if (i != len-1) {
                printf("%d ", array[i]);
            } else {
                printf("%d\n", array[i]);
            }
        }
    }

    return 0;
}
