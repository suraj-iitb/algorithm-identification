#include <stdio.h>
#define NOT_FOUND 0


int linearSearch(int data[], int num1, int key);

int main(void)
{
    int i, num1, num2, key, data[10000 + 1], count = 0;

    scanf("%d", &num1);
    for (i = 0; i < num1; i++) {
        scanf("%d", &data[i]);
    }

    scanf("%d", &num2);
    for (i = 0; i < num2; i++) {
        scanf("%d", &key);
        if (linearSearch(data, num1, key) != NOT_FOUND) count++;
    }

    printf("%d\n", count);

    return 0;
}

int linearSearch(int data[], int num1, int key)
{
    int i = 0;

    data[num1] = key;

    while (data[i] != key) {
        i++;
    }
    if (i == num1) return NOT_FOUND;

    return 1;
}

