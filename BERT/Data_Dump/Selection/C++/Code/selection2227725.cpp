#include <stdio.h>
#include <algorithm>

#define MAX 100

using namespace std;

int numbers[MAX];

int selectionSort(int a[], int n)
{
    int i, j, place, swapNum = 0;
    for (i = 0; i < n - 1; i++) {
        place = i;
        for (j = i; j < n; j++) {
            if (a[j] < a[place]) place = j;
        }
        swap(a[i], a[place]);
        if (i != place) swapNum++;
    }
    return swapNum;
}

int main()
{
    // input
    int n, i, swapNum;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    // processing
    swapNum = selectionSort(numbers, n);
    // output
    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", numbers[i]);
    }
    printf("\n");
    printf("%d\n", swapNum);

    return 0;
}
