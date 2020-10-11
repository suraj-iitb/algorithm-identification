#include <stdio.h>

#define MAX 100

int main(void)
{
    int i, j;

    int nums[MAX];

    int length;
    scanf("%d", &length);

    for (i = 0; i < length; i++) {
        scanf("%d", &nums[i]);
        if (i != 0) {
            printf(" ");
        }
        printf("%d", nums[i]);
    }
    printf("\n");

    int key;
    for (i = 1; i < length; i++) {
        key = nums[i];
        j = i - 1;
        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;

        for (j = 0; j < length; j++) {
            if (j != 0) {
                printf(" ");
            }
            printf("%d", nums[j]);
        }
        printf("\n");
    }

    return 0;
}
