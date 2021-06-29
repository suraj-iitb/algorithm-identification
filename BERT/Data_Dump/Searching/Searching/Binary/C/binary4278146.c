#include <stdio.h>
#define NOT_FOUND 0

int binarySearch(int data[], int key, int n);

int main(void)
{
    int num1, num2, i, key, data[100000], count = 0;

    scanf("%d", &num1);
    for (i = 0; i < num1; i++) {
        scanf("%d", &data[i]);
    }

    scanf("%d", &num2);
    for (i = 0; i < num2; i++) {
        scanf("%d", &key);
        if (binarySearch(data, key, num1) != NOT_FOUND) count++;
    }

    printf("%d\n", count);

    return 0;
}

int binarySearch(int data[], int key, int n)
{
    int left = 0;
    int right = n;
    while (left < right) {
        int mid = (left + right) / 2;

        if (data[mid] == key) {
            return 1;
        } else if (key < data[mid]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return NOT_FOUND;
}

